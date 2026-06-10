#include <coroutine>
#include <iostream>

struct Awaiter {
    bool await_ready() {
        std::cout << "await ready\n";
        return false;
    }
    void await_suspend(std::coroutine_handle<> handle) { std::cout << "await suspend\n"; }
    void await_resume() { std::cout << "await resume\n"; }
};

struct Generator {
    struct promise_type {
        int current_value{};

        Generator get_return_object() {
            return std::coroutine_handle<promise_type>::from_promise(*this);
        }
        std::suspend_always initial_suspend() {
            std::cout << "suspend generator\n";
            return {};
        }
        std::suspend_always final_suspend() noexcept {
            std::cout << "final generator\n";
            return {};
        }
        std::suspend_always yield_value(int v) {
            current_value = v;
            return {};
        }
        auto await_transform(int x) noexcept {
            std::cout << "\nAwait transform: " << x << '\n';
            return std::suspend_always{};
        }
        void return_void() { std::cout << "return void generator\n"; }
        void unhandled_exception() { std::cout << "unhandled generator\n"; }
    };
    std::coroutine_handle<promise_type> handle;
    Generator(const std::coroutine_handle<promise_type> &h) : handle(h) {}
    ~Generator() { handle.destroy(); }

    int next() {
        handle.resume();
        return handle.promise().current_value;
    }

    bool done() { return handle.done(); }
};

struct Task {
    struct promise_type {
        Task get_return_object() {
            std::cout << "get_return_object" << '\n';
            return std::coroutine_handle<promise_type>::from_promise(*this);
        }
        std::suspend_always initial_suspend() {
            std::cout << "initial suspend" << '\n';
            return {};
        }
        std::suspend_always final_suspend() noexcept {
            std::cout << "final_suspend" << '\n';
            return {};
        }
        auto await_transform(int x) noexcept {
            std::cout << "\nAwait transform: " << x << '\n';
            return std::suspend_always{};
        }
        void unhandled_exception() { std::cout << "unhandled_exception" << '\n'; }
        void return_void() { std::cout << "return_void" << '\n'; }
    };
    std::coroutine_handle<promise_type> m_Handle;
    Task(const std::coroutine_handle<promise_type> &handle) : m_Handle(handle) {}
    ~Task() { m_Handle.destroy(); }
};

Generator counter(int from, int to) {
    for (int i = from; i < to; i++) {
        co_yield i;
    }
}

Task co_function() {
    std::cout << "<Coroutine - Started>" << '\n';
    std::cout << "<Coroutine - Executing coroutine function>" << '\n';
    // co_await std::suspend_always{};
    co_await Awaiter{};
    std::cout << "<Coroutine - Resuming coroutine...>" << '\n';
    std::cout << "<Coroutine - Executing coroutine function>" << '\n';
    std::cout << "<Coroutine - Resuming coroutine function>" << '\n';
    co_await 0;
    co_return;
}
int main() {
    std::cout << "Main Coroutine" << '\n';
    auto task = co_function();
    while (!task.m_Handle.done()) {
        std::cout << "\nmain - resuming coroutine\n";
        task.m_Handle.resume();
    }
    std::cout << "main - coroutine is done\n";
    auto gen = counter(1, 10);
    while (!gen.done()) {
        std::cout << "generator: " << gen.next() << '\n';
    }
    return 0;
}

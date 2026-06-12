#include <iostream>
#include <latch>
#include <semaphore>
#include <stop_token>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;
void DoWork(int duration, const std::string &name) {
    for (int i = 0; i < duration; i++) {
        std::cout << "name: " << name << '\n' << std::flush;
        std::this_thread::sleep_for(1s);
    }
}

// std::counting_semaphore sem{3};
std::binary_semaphore sem{1};
void Worker(std::stop_token, int duration, const std::string &name) {
    sem.acquire();
    std::cout << "started initialization\n";
    DoWork(duration, name);
    std::cout << "finished initialization\n";
    DoWork(20, name);
    sem.release();
}

void Task(std::stop_token st) {
    // do_something(5, "Task");
    while (true) {
        std::cout << '.';
        std::this_thread::sleep_for(1s);
        if (st.stop_requested()) {
            std::cout << "Thread received stop" << '\n';
            return;
        }
    }
}

int main() {
    std::cout << "main" << '\n';
    std::vector<std::jthread> threads{};
    threads.emplace_back([](std::stop_token _) { Worker(_, 3, "A"); });
    threads.emplace_back([](std::stop_token _) { Worker(_, 7, "B"); });
    threads.emplace_back([](std::stop_token _) { Worker(_, 4, "C"); });
    threads.emplace_back([](std::stop_token _) { Worker(_, 8, "D"); });
    for (auto &t : threads)
        t.join();
    std::cout << "main finished\n";
}

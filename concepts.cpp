#include <concepts>
#include <format>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename T>
concept Pointer = std::is_pointer_v<T>;

template <typename T>
    requires Pointer<T>
void apply_ptr(T ptr) {
    std::cout << *ptr << '\n';
}

template <typename T, std::enable_if_t<std::is_integral_v<T>> * = nullptr>
T divide(T first, T second) {
    return first / second;
}

template <typename Callable, typename... Args> bool all_of(Callable callable, Args... args) {
    return (callable(args) && ...);
}

bool even(int x) { return x % 2 == 0; }
template <std::integral T> T concepts_divide(T first, T second) { return first / second; }

template <typename T>
concept LessThan = requires(T first, T second) {
    { first < second } noexcept -> std::convertible_to<bool>;
};

template <LessThan T> bool isGreater(T first, T second) { return first < second; }

template <typename T, typename Callable> void print(T arg, Callable callable) {
    callable();
    std::cout << arg << '\n';
    callable();
}

class Type {
  public:
    Type() = default;
    Type(Type &&) = default;
    Type(const Type &) = delete;
};

template <std::move_constructible T> void insert(T &&arg) {
    std::vector<T> v;
    v.emplace_back(std::forward<T>(arg));
}

int main() {
    std::cout << "main" << '\n';
    std::cout << std::format("division of {} by {} is {}", 6, 3, divide(6, 3)) << '\n';
    std::cout << std::format("division of {} by {} is {}", 6, 3, concepts_divide(6, 3)) << '\n';
    bool is_greater = isGreater(6, 5);
    std::cout << std::boolalpha << "is greater: " << is_greater << '\n';
    insert(Type{});
    int x = 40;
    int *ptr_x = &x;
    apply_ptr(ptr_x);
    print("ciao", []() { std::cout << "--------\n"; });
    std::cout << all_of(even, 4);
    return 0;
}

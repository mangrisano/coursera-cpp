#include <format>
#include <iostream>

template <typename... Args> void println(std::format_string<Args...> fmt, Args &&...args) {
    std::cout << std::format(fmt, std::forward<Args>(args)...);
}

int main() {
    auto value = 45;
    println("{0}", value);
}

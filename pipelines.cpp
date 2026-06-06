#include <format>
#include <iostream>
#include <random>
#include <ranges>

template <typename Container> void print(Container &&container, std::string_view message = "") {
    std::cout << std::format("{}: [ ", message);
    for (const auto &element : container) {
        std::cout << element << " ";
    }
    std::cout << "]\n";
}

// Use && in template for accepting lvalue and rvalue. It's called Universal
// Reference. Basically, & accepts only lvalues that exist. && accepts
// everything.
template <std::ranges::range Range> void print_range(Range &&range, std::string_view message = "") {
    std::cout << std::format("{}: [ ", message);
    for (const auto &element : range) {
        std::cout << element << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "Main" << '\n';
    std::vector<int> data(10);
    std::random_device rd;
    std::ranges::generate(data, [&]() { return rd() % 100; });
    auto odd = std::views::filter(data, [](int x) { return x % 2 != 0; });
    auto view = data | std::views::filter([](int x) { return x % 2 != 0; }) |
                std::views::filter([](int x) { return x >= 30; });
    print(view, "view");
    print(data, "vector");
    print(odd, "odds");
    print_range(data, "rangeprint");
    print(std::views::single(50), "single");
    auto range = std::views::iota(1, 25);
    print(range, "rangeiota");
    return 0;
}

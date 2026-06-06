#include <algorithm>
#include <format>
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

template <typename Container>
void print(const Container &container, const std::string_view message = "", char separator = ' ') {
    std::cout << "Printing..." << '\n';
    std::cout << std::format("{}: [ ", message);
    for (const auto &element : container) {
        std::cout << std::format("{}{}", element, separator);
    }
    std::cout << "]\n";
}
int main() {
    std::cout << "main" << '\n';
    std::vector<int> vec_i(10);
    std::random_device rd;
    std::ranges::generate(vec_i, [&rd]() { return rd() % 10; });
    print(vec_i, "vector");
    std::ranges::for_each(vec_i, [](int &element) {
        if (element % 2 != 0) {
            element *= 2;
        }
    });
    print(vec_i, "doubled");
    auto found = std::ranges::find(vec_i, 2);
    if (found != vec_i.end()) {
        std::cout << "found: " << *found << '\n';
    } else {
        std::cout << "not found" << '\n';
    }
    auto ranges_found = std::ranges::find(vec_i, 2);
    if (ranges_found != vec_i.end()) {
        std::cout << "found: " << *ranges_found << '\n';
    } else {
        std::cout << "not found" << '\n';
    }
    std::ranges::shuffle(vec_i, rd);
    print(vec_i, "again vector shuffle");
    std::ranges::for_each(vec_i, [](int &element) {
        if (!(element % 2)) {
            element *= 2;
        }
    });
    std::ranges::sort(vec_i);
    print(vec_i, "even doubled");
    return 0;
}

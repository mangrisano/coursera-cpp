#include <bitset>
#include <format>
#include <iomanip>
#include <iostream>

void F() {}
void G() noexcept {}

int main() {
    std::cout << std::boolalpha;
    std::cout << "noexcept: " << noexcept(F()) << '\n';
    std::cout << "noexcept: " << noexcept(G()) << '\n';
    auto value = 128u;
    std::string_view luigi{"luigi"};
    std::cout << "Binary: " << std::bitset<8>{value} << '\n';
    std::cout << std::setw(10) << luigi; // Riempie con spazi vuoti la lunghezza n passata.
    std::cout << std::format("first number {} and second is {}", 1, 2);
    return 0;
}

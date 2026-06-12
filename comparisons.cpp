#include <compare>
#include <iostream>
#include <type_traits>

struct Type {
    int value{};
    char array[8]{};
    int *ptr{};

    auto operator<=>(const Type &) const = default;
};

class Number {
  public:
    Number() = default;

    constexpr Number(int number) : m_number{number} {
        if (!std::is_constant_evaluated()) {
            std::cout << m_number << '\n';
        }
    }

    constexpr int get_number() const noexcept { return m_number; }
    constexpr void set_number(int other) noexcept { m_number = other; }

    auto operator<=>(const Number &) const = default;

    friend std::ostream &operator<<(std::ostream &os, const Number &number);

  private:
    int m_number{};
};

std::ostream &operator<<(std::ostream &os, const Number &number) {
    os << number.m_number;
    return os;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "Main\n";

    Number number{42};
    std::cout << "the result is: " << number.get_number() << '\n';

    number.set_number(55);
    std::cout << "the result is: " << number.get_number() << '\n';

    Number first{10};
    Number second{20};
    Number third{10};

    bool is_equals = first == second;
    bool is_other_equals = first == third;
    bool is_greater = first > second;
    bool is_less = first < second;

    std::cout << "The numbers are equals: " << is_equals << '\n';
    std::cout << "The numbers are not equals: " << !is_equals << '\n';
    std::cout << "The numbers are equals: " << is_other_equals << '\n';
    std::cout << "The first number: " << first << '\n';
    std::cout << "The first number is lesser than second: " << is_less << '\n';
    std::cout << "The first number is greater than second: " << is_greater << '\n';

    int num = 45;
    Type a{.value = 100, .array = "C++", .ptr = &num};
    std::cout << "the a value is: " << a.value << '\n';

    return 0;
}

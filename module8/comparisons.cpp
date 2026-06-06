#include <ios>
#include <iostream>

struct Type {
    int value{};
    char array[8]{};
    int *ptr{};
    auto operator<=>(const Type &rhs) const = default;
};

class Number {

  public:
    constexpr Number() = default;
    constexpr Number(int number) : m_number{number} { std::cout << m_number << '\n'; }
    constexpr int get_number() const { return m_number; }
    constexpr void set_number(int other) { m_number = other; }
    constexpr bool operator==(const Number &rhs) const noexcept { return m_number == rhs.m_number; }
    constexpr bool operator!=(const Number &rhs) const noexcept {
        return !(m_number == rhs.m_number);
    }
    constexpr bool operator<(const Number &rhs) const noexcept { return m_number < rhs.m_number; }
    constexpr bool operator>(const Number &rhs) const noexcept { return m_number > rhs.m_number; }
    auto operator<=>(const Number &rhs) const = default;
    friend std::ostream &operator<<(std::ostream &os, const Number &number);

  private:
    int m_number;
};

std::ostream &operator<<(std::ostream &os, const Number &number) {
    os << number.m_number;
    return os;
}

int main() {

    std::cout << std::boolalpha;
    std::cout << "Main" << '\n';
    Number number{42};
    int result = number.get_number();
    std::cout << "the result is: " << result << '\n';
    number.set_number(55);
    std::cout << "the result is: " << number.get_number() << '\n';
    Number first{10};
    Number second{20};
    Number third{10};
    bool is_equals = first.get_number() == second.get_number();
    bool is_other_equals = first.get_number() == third.get_number();
    bool is_greater = first.get_number() > second.get_number();
    bool is_less = first.get_number() < second.get_number();
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

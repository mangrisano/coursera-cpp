#include <compare>
#include <format>
#include <iostream>

class Number {

  public:
    Number() = default;
    Number(int number) : m_number{number} { std::cout << "the number is: " << m_number << '\n'; }
    constexpr int get() const { return m_number; }
    constexpr void set(int number) { m_number = number; }
    auto operator<=>(const Number &rhs) const = default;

  private:
    int m_number{};
};

class String {

  public:
    String(const char *p_str = "") : m_str{std::move(p_str)} {
        std::cout << "the string is: " << p_str << '\n';
    }
    auto operator<=>(const String &rhs) const = default;
    int compare(const String &rhs) const {
        auto size = std::min(m_str.size(), rhs.m_str.size());
        int comp{};
        for (size_t i = 0; i < size; i++) {
            auto lhs_ch = std::tolower(m_str[i]);
            auto rhs_ch = std::tolower(rhs.m_str[i]);
            if (lhs_ch != rhs_ch) {
                comp = lhs_ch < rhs_ch ? -1 : +1;
                break;
            }
        }
        return comp;
    }

  private:
    std::string m_str{};
};

int main() {
    std::cout << "Main" << '\n';
    int x{1}, y{2};
    auto ordering = x <=> y;
    std::cout << typeid(ordering).name() << '\n';
    if (ordering == std::strong_ordering::less)
        std::cout << "x < y" << '\n';
    if (ordering == std::strong_ordering::greater)
        std::cout << "x > y" << '\n';
    if (ordering == std::strong_ordering::equal)
        std::cout << "x = y" << '\n';
    if (ordering == std::strong_ordering::equivalent)
        std::cout << "x = y" << '\n';
    Number first{3}, second{3};
    ordering = first <=> second;
    if (ordering == std::strong_ordering::less)
        std::cout << "x < y" << '\n';
    if (ordering == std::strong_ordering::greater)
        std::cout << "x > y" << '\n';
    if (ordering == std::strong_ordering::equal)
        std::cout << "x = y" << '\n';
    if (ordering == std::strong_ordering::equivalent)
        std::cout << "x = y" << '\n';
    String s1{"ciao"}, s2{"ciao"};
    if (s1 == s2)
        std::cout << "string are equals" << '\n';
    if (s1 < s2)
        std::cout << "s1 < s2" << '\n';
    if (s1 > s2)
        std::cout << "s1 > s2" << '\n';
    int comp_result = s1.compare(s2);
    std::cout << "the compare between s1 and s2 is: " << comp_result << '\n';
    return 0;
}

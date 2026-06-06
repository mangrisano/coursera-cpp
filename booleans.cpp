#include <concepts>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <utility>

template <typename T>
concept StringType = std::is_same_v<T, std::string> || std::is_same_v<T, std::string_view>;

void print_std_string(const std::string &str) { std::cout << str << '\n'; }

void print_std_string_view(std::string_view str) { std::cout << str << '\n'; }

void print_optional(const std::optional<std::string> &str) {
    std::cout << str.value_or("pesce") << '\n';
}

template <StringType T> class String {
    T m_str{};

  public:
    String(const T &str) : m_str{str} {}
    String(T &&str) : m_str{std::move(str)} {}
    const T &get() const { return m_str; }

    template <typename V> friend void print(const String<V> &str);
};

template <typename V> void print(const String<V> &str) { std::cout << str.m_str << '\n'; }

int main() {
    std::string s1{"C++"};
    std::string_view s2{"C"};
    print_std_string(s1);
    print_std_string_view(s2);
    std::optional<std::string> op = "capocchia";
    print_optional(op);
    String<std::string> s{"ciao"};
    std::cout << s.get() << '\n';
    String<std::string_view> forte{"ciaoamici"};
    print(s);
    print(forte);
}

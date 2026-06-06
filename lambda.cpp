#include <iostream>
#include <memory>
#include <set>
#include <string>

template <typename T> using Ptr = std::unique_ptr<T, decltype([](T *p) { delete p; })>;

struct Name {
    std::string mName{};
    Name(std::string name) : mName{std::move(name)} {}
    friend std::ostream &operator<<(std::ostream &os, const Name &name) { return os << name.mName; }
};

class Person {
    std::string m_Name{};

  public:
    Person(std::string name) : m_Name{std::move(name)} {}

    auto getPrintOperation(int id) {
        return [=, *this]() { std::cout << "id: " << id << " name: " << m_Name << '\n'; };
    }
};

int sum(int x, int y);

auto getOperation(const char *pName) {
    Person person{pName};
    return person.getPrintOperation(100);
}

int main() {
    auto lambda_deleter = [](auto *p) { delete p; };
    std::unique_ptr<int, decltype(lambda_deleter)> p1{new int, lambda_deleter};
    std::unique_ptr<int, decltype([](auto *p) { delete p; })> p2{new int};
    Ptr<int> pInt{new int};
    Ptr<float> pFloat{new float};
    auto name_compare = [](const auto &firstName, const auto &secondName) {
        return firstName.mName < secondName.mName;
    };
    std::set<Name, decltype(name_compare)> names{{Name{"michele"}, Name{"luca"}, Name{"angelo"}},
                                                 name_compare};
    ;
    for (const auto &name : names) {
        std::cout << name << '\n';
    }
    auto string_compare = [](auto first, decltype(first) second) {
        return first > second ? first : second;
    };
    auto op = getOperation("michele");
    op();
    std::cout << string_compare("bello", "michele") << '\n';
    return 0;
}

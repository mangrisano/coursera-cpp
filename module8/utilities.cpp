#include <iostream>
#include <set>
#include <string>

struct Person {
    std::string name{};
    int age{};
    char gender{};

    auto operator<=>(const Person &) const = default;
};

struct PersonCompare {
    bool operator()(const Person &first, const Person &second) const {
        if (first.age != second.age) {
            return first.age < second.age;
        }
        return first.name < second.name;
    }
};

int main() {
    std::cout << "Main" << '\n';
    std::set<Person, PersonCompare> people{};
    people.insert({"michele", 37, 'M'});
    people.insert({"luana", 3, 'F'});
    people.insert({"luana", 3, 'F'});
    for (const auto &person : people) {
        std::cout << person.name << '\n';
    }
    return 0;
}

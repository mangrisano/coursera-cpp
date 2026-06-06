#include <iostream>
#include <string>

struct Point {
    int x;
    int y;
};

class Person {
    std::string m_Name;
    int m_Id;

  public:
    Person(const std::string name, int id) : m_Name(name), m_Id(id) {}
    static void foo(const Person &person) {
        auto n = person.m_Name;
        auto [name, id] = person;
        std::cout << "name: " << name << " id: " << id << std::endl;
    }

    friend void print(const Person &person);
};

void print(const Person &person) { std::cout << person.m_Name << " " << person.m_Id << std::endl; }

int main() {
    Person person{"Michele", 2};
    Person::foo(person);
    print(person);
    return 0;
}

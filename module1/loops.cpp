#include <iostream>
#include <list>

class Names {
    std::list<std::string> m_Names{};

  public:
    Names(std::list<std::string> names) : m_Names{std::move(names)} {}
    ~Names() { std::cout << "Destructor called" << std::endl; }
    inline const std::list<std::string> &get_names() { return m_Names; }
    inline static Names create() { return Names({"Antonio", "Giuseppe", "Damiano"}); }
    inline void print_names() {
        for (const auto &name : m_Names)
            std::cout << "the name is: " << name << std::endl;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::list<int> lst{1, 2, 3};
    for (auto element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    for (auto element : lst) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    Names names({"michele", "diego", "carmine"});
    Names other_names = Names::create();
    for (const auto &name : other_names.get_names()) {
        std::cout << "other name: " << name << std::endl;
    }
    std::list<std::string> all_names = names.get_names();
    for (const auto &name : all_names) {
        std::cout << name << std::endl;
    }
    names.print_names();
    other_names.print_names();
    return 0;
}
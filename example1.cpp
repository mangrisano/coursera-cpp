#include <iostream>

struct Department {
    std::string name;
    std::string manager;
};

struct Employee {
    std::string name;
    int id;
    Department dept{.name = "unallocated"};
};

int main() {
    Employee employee_1 =
        Employee{.name = "Michele Angrisano", .id = 1, .dept{.name = "Engineer", .manager = "CDB"}};
    std::cout << "Employee: " << employee_1.name << " with id: " << employee_1.id
              << " belongs to department: " << employee_1.dept.name
              << " with manager name: " << employee_1.dept.manager << std::endl;
    return 0;
}
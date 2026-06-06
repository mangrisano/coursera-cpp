#include <iostream>

constexpr int square(int x) {
    try {
        return x * x;
    } catch (...) {
        return 0;
    }
}

struct A {
    virtual constexpr int get() const { return 1; }
};

struct B : A {
    constexpr int get() const override { return 2; }
};

constexpr int invoke(const A *a) { return a->get(); }

int main() {
    auto result = square(4);
    constexpr B b;
    A a;
    std::cout << b.get() << std::endl;
    std::cout << invoke(&a) << std::endl;
    std::cout << invoke(&b) << std::endl;
    std::cout << "result: " << result << std::endl;
    static_assert(invoke(&b) == 2);
    return 0;
}
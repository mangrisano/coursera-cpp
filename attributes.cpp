#include <cstddef>
#include <iostream>

struct DBInfo {
    DBInfo() {}
};

[[nodiscard("db failure")]] DBInfo get() {
    DBInfo info;
    return info;
}

// Il discard serve quando vuoi che il valore di ritorno venga usato,
// altrimenti warning
[[nodiscard("alloc failure")]] void *row_alloc(size_t size) { return operator new(size); }

[[nodiscard("registered failure")]] int register_something() { return 100; }

void unregister_something(int token) { std::cout << token << '\n'; }

enum class [[nodiscard("enum failure")]] ErrorCode { SUCCESS, FAILURE, WARNING };

ErrorCode create_component() { return ErrorCode::FAILURE; }
int main() {
    // DBInfo g = get();
    //  int *ptr = (int *)row_alloc(100);
    //  register_something(); // Return value non usato -> warning
    //  create_component();   // Return value non usato -> warning

    DBInfo{};
    return 0;
}

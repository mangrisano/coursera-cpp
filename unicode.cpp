#include <iostream>
#include <string>

int main() {
    char8_t ch = u8'a';
    const char8_t *p = u8"Hello";
    std::u8string str{u8"ciaolota"};
    std::cout << (char)ch << " " << (char)*p << " " << reinterpret_cast<const char *>(str.c_str())
              << std::endl;
    return 0;
}
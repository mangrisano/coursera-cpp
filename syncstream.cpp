#include <iostream>
#include <syncstream>
#include <thread>
#include <vector>

void WriteStream(int /*id*/) {
    for (int i = 0; i < 10; i++) {
        std::osyncstream s_out{std::cout};
        s_out << "The " << "quick " << "brown" << '\n';
    }
}

int main() {
    std::vector<std::jthread> threads{};
    for (int i = 0; i < 5; i++) {
        threads.emplace_back(WriteStream, i);
    }
}

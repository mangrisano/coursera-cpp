#include <iostream>

enum class Color { Red, Green, Blue };

std::string_view to_string(Color color) {
    using enum Color;
    switch (color) {
    case Red:
        return "Red";
    case Color::Green:
        return "Green";
    case Color::Blue:
        return "Blue";
    default:
        return "";
    };
}

class Socket {
  public:
    enum SocketType { STREAM, DATAGRAM };
};

void create_socket(Socket::SocketType type) { std::cout << type << '\n'; }

int main() {
    std::cout << "Main" << '\n';
    std::string_view color = to_string(Color::Red);
    std::cout << "the color is: " << color << '\n';
    create_socket(Socket::STREAM);
    return 0;
}

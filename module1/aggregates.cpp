#include <iostream>

struct Point {
    int x;
    int y;
};

struct TPoint : Point {
    int z;
};

union Data {
    int x;
    char y;
    double z;
};

void print_points(Point point) {
    std::cout << "first point: " << point.x << " - second point: " << point.y << std::endl;
}

void print_three_points(TPoint point) {
    std::cout << "first point: " << point.x << " - second point: " << point.y
              << " - third point: " << point.z << std::endl;
}
int main() {
    Data d{.y = 'c'}; // in union aggregate you can set just one of those fields.
    Point point{1, 2};
    Point new_point{.x = 10, .y = 20};
    TPoint tpoint{{1, 2}, 3};
    std::cout << d.x << std::endl;
    print_points({3, 4});
    print_points(point);
    print_points(new_point);
    print_three_points(tpoint);
    return 0;
}
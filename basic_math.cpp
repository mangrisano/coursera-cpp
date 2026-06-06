module basic_math;

namespace Math {
int add(int first, int second) { return first + second; }
int sub(int first, int second) { return first - second; }
float division(int first, int second) {
    if (second <= 0) {
        return -1;
    }
    return first / second;
}
} // namespace Math

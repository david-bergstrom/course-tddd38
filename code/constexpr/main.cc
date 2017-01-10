#include<iostream>

constexpr double PI = 3.14159265358979323846;

constexpr long long factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

constexpr double to_radians(double d) {
    return d * PI/180;
}

int main() {
    constexpr auto x = factorial(20); 
    std::cout << x << std::endl;
    constexpr auto y = to_radians(180);
    std::cout << y << std::endl;
}

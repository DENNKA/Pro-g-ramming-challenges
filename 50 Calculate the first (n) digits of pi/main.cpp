#include <iostream>
#include <iomanip>

// calculate PI with Taylor Series

long double calcPi(int iterations) {
    long double pi = 1;
    bool minus = true;
    for (int i = 3; i < iterations * 2; i+=2, minus = !minus) {
        if (minus) {
            pi = pi - 1/(double)i;
        } else {
            pi += 1/(double)i;
        }
    }
    return pi * 4;
}

int main() {
    int n, iterations;
    std::cin >> n >> iterations;

    std::cout << std::fixed << std::setprecision(n - 1) << calcPi(iterations) << std::endl;
}

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    for (int i = 1, n = argc > 1 ? std::stoi(argv[1]) : 100; i <= n; i++)
        std::cout << (i % 15 == 0 ? "Fizz Buzz" : i % 3 == 0 ? "Fizz" : i % 5 == 0 ? "Buzz" : std::to_string(i)) << ", ";
    std::cout << std::endl;
}

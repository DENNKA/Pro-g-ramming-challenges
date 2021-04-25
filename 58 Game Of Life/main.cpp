#include "GameOfLife.hpp"

int main(int argc, char** argv) {
    if (argc > 3) {
        GameOfLife gameOfLife(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
        gameOfLife.run();
    }
    else if (argc > 2) {
        GameOfLife gameOfLife(atoi(argv[1]), atoi(argv[2]));
        gameOfLife.run();
    }
    else {
        GameOfLife gameOfLife;
        gameOfLife.run();
    }
}

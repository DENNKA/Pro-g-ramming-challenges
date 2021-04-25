#include "GameOfLife.hpp"

GameOfLife::GameOfLife(int x, int y, int sleep) {
    #ifdef LINUX
        if (!x && !y) {
            struct winsize w;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

            y = w.ws_row;
            x = w.ws_col;
        }
    #endif
    #ifdef WINDOWS
        if (!x && !y) {
            x = 10, y = 10;
        }
    #endif
    width = x;
    height = y;
    this->sleep = sleep;

    world.resize(y);
    for (auto& line : world) {
        line.resize(x);
    }
}

void GameOfLife::random() {
    srand(time(NULL));
    for (int i = 0; i < world.size(); i++) {
        for (int j = 0; j < world[i].size(); j++) {
            world[i][j] = rand() % 2;
        }
    }
}

void GameOfLife::run() {
    random();
    while (true) {
        update();
        write();
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
    }
}

int GameOfLife::getNeighbors(int i, int j){
    int counter = 0;
    for (int ii = i - 1; ii <= i + 1; ii++) {
        for (int jj = j - 1; jj <= j + 1; jj++) {
            if (ii == i && jj == j) {continue;}
            if (oldWorld.at(ii < 0 ? height - 1 : ii >= height ? 0 : ii).at(jj < 0 ? width - 1 : jj >= width ? 0 : jj)) {
                counter++;
            }
        }
    }
    return counter;
}

void GameOfLife::update() {
    oldWorld = world;
    for (int i = 0; i < oldWorld.size(); i++) {
        for (int j = 0; j < oldWorld[i].size(); j++) {
            auto counter = getNeighbors(i, j);
            if (counter == 3) world[i][j] = true;
            if (counter < 2 || counter > 3) world[i][j] = false;
        }
    }
}

void GameOfLife::write() {
    #ifdef WINDOWS
        COORD topLeft  = { 0, 0 };
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO screen;
        DWORD written;

        GetConsoleScreenBufferInfo(console, &screen);
        FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        SetConsoleCursorPosition(console, topLeft);
    #endif
    #ifdef LINUX
        std::cout << "\x1B[2J\x1B[H";
    #endif
    for (const auto& line : world) {
        for (const auto& cell : line) {
            std::cout << (cell ? '#' : ' ');
        }
        std::cout << std::endl;
    }
}

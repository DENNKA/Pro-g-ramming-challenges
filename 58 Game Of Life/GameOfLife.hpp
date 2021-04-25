#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <windows.h>
    #define WINDOWS
#else
    #define LINUX
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

class GameOfLife {
    public:
        GameOfLife(int x = 0, int y = 0, int sleep = 100);
        void random();
        void run();
        void update();
        void write();
    private:
        int getNeighbors(int i, int j);
        std::vector<std::vector<bool>> world;
        std::vector<std::vector<bool>> oldWorld;
        int height;
        int width;
        int sleep;
};

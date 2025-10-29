#include <chrono>
#include <iostream>

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    static int count;
    int id;

    Timer() : id(++count) {
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Timer #" << id << " started" << std::endl;
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer #" << id << " took " << ms << "ms" << std::endl;
    }
};

int Timer::count = 0;

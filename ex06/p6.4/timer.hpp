#ifndef TIMER.HPP
#define TIMER .HPP
#include <chrono>

class Timer
{
    Timer();
    void start()
    {
        auto s = std::chrono::high_resolution_clock::now;
    }
    void end()
    {
        auto e = std::chrono::high_resolution_clock::now;
    }
    std::chrono::seconds duration()
    {
        return std::chrono::duration_cast<std::chrono::seconds>(e - s);
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> s;
    std::chrono::time_point<std::chrono::high_resolution_clock> e;
}
#endif
#include <iostream>
#include <chrono> // C++11

unsigned long long fibonacci(unsigned n)
{
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    // if auto is not available, best to use a typedef (otherwise WET!)
    // typedef std::chrono::high_resolution_clock::time_point
    //         time_point_t;

    auto start = std::chrono::high_resolution_clock::now(); // start
    // time_point_t start = std::chrono::high_resolution_clock::now();
    std::cout << "f(42) = " << fibonacci(42) << std::endl;
    auto end = std::chrono::high_resolution_clock::now(); // end
    // time_point_t end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;
}

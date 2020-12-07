#include <iostream>
#include <chrono> // C++11

int main()
{

    // if auto is not available, best to use a typedef (otherwise WET!)
    // typedef std::chrono::high_resolution_clock::time_point
    //         time_point_t;

    int vec[1000];

    int Mrep = 1000000; // number of repetitions
    auto start = std::chrono::high_resolution_clock::now();
    // time_point_t start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < Mrep; j++)
    {
        for (unsigned int i = 0; i < 1000; i++)
        {
            vec[i] = 1;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    // time_point_t stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time = stop - start;
    std::cout << "Loop took: " << time.count() << " seconds." << std::endl;
}

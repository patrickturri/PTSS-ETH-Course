#include <iostream>
#include <random> // C++11

int main()
{

    // default random engine
    std::default_random_engine e;
    e.seed(43); // set seed

    // other choices
    // Mersenne-twisters
    std::mt19937 rng1;
    std::mt19937_64 rng2;

    // lagged Fibonacci generators
    std::ranlux24_base rng3;
    std::ranlux48_base rng4;

    // linear congruential generators
    std::minstd_rand0 rng5;
    std::minstd_rand rng6;

    // min & max numbers
    std::cout << "min: " << e.min() << '\n';
    std::cout << "max: " << e.max() << '\n';

    // generate 5 random numbers
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "i = " << i << ": " << e << '\n';
    }
}

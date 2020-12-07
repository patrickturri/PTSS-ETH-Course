#include "simpson_rule.hpp"

#include <cmath>
#include <iostream>
#include <fstream>

double my_sin(double value)
{
    return std::sin(value);
}

int main()
{

    std::cout << "Integrator maximum resolution?" << std::endl;
    size_t N;
    std::cin >> N;
    std::cout << N << std::endl;

    std::ofstream of("data/results.txt");
    of.precision(15);
    for (size_t i = 2; i <= N; ++i)
    {
        of << i << "\t" << integrate(0, M_PI, i, my_sin) << std::endl;
    }

    return 0;
}

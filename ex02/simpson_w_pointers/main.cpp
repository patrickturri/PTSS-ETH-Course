#include <iostream>
#include <cmath>
#include "simpson_rule.hpp"
#define _USE_MATH_DEFINES

double my_sin(double x)
{
    return sin(x);
}
int main()
{
    int max_bins = 10;
    int bins = rand();
    std::cout << "Integral of sin(x) in [0, pi] is " << simpson_rule(0.0, M_PI, bins, my_sin) << "\n";
    // iterate over an increasing number of bins
    for (int i = 1; i < max_bins; i++)
    {
        std::cout << i << "   " << simpson_rule(0.0, M_PI, i, my_sin) << "\n";
    }
}

#include <iostream>
#include <math.h>

int main()
{
    double epsilon = 1.0;

    while ((1.0 + 0.5 * epsilon) != 1.0)
    {
        epsilon = 0.5 * epsilon;
    }
    std::cout
        << "The machine epsilon is: " << epsilon << "\n";
}
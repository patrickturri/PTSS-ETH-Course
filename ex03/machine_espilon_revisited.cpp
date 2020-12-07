#include <iostream>
#include <math.h>

template <typename e>
e calculate_epsilon(e epsilon)
{
    while ((1.0 + 0.5 * epsilon) != 1.0)
    {
        epsilon = 0.5 * epsilon;
    }
    return epsilon;
}

int main()
{
    std::cout
        << "The machine epsilon is: " << calculate_epsilon<double>(1.0) << "\n";
}
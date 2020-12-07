#include "min.hpp"
#include <iostream>

int main()
{

    std::cout << "min(1  ,2) = " << min(1, 2) << std::endl;
    std::cout << "min(1.2,2.3) = " << min(1.2, 2.3) << std::endl;
    std::cout << "min(1  ,2.3) = " << min(1, 2.3) << std::endl;
    std::cout << "min(1.f,2   ) = " << min(1.f, 2) << std::endl;

    int a = 1;
    float b = 3;
    double c = min(a, b);
    std::cout << "c = " << c << std::endl;

    // what about? can you fix it?
    int d = 1;
    double e = 3;
    double f = min(d, e);
    std::cout << "f = " << f << std::endl;
}

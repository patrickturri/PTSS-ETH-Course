#include <iostream>
#include "point.hpp"

int main()
{

    Point p0;         // default construction: p0 = (0,0)
    Point p1(1., 2.); // p1 = (1,2)
    Point p2(p1);     // copy construction: p2 = (1,2) (= p1)
    Point p3;         // default construction: p3 = (0,0)
    p3 = p2;          // copy assignment p3 = (1,2) (= p2)
    std::cout << "p0 = " << p0 << '\n';
    std::cout << "p1 = " << p1 << '\n';
    std::cout << "p2 = " << p2 << '\n';
    std::cout << "p3 = " << p3 << '\n';

    p0 -= p1;
    std::cout << "p0 -= p1; p0 = " << p0 << '\n';

    std::cout << "p1 + p3 = " << p1 + p3 << '\n';
}

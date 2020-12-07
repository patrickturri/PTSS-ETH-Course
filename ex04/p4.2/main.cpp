#include "simpson_functors.hpp"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

class Decay
{
public:
    Decay(const double l = 1.0) : lambda_(l) {}
    // function call operator
    double operator()(const double x) const
    {
        return exp(-lambda_ * x);
    }

private:
    const double lambda_;
};

const double lambda = 2.;

int main()
{
    Decay f(lambda);
    const unsigned bins = 4;
    const double a = 0;
    const double b = 8;
    cout << "int_a^b exp(-lambda*x) dx  = " << simpson(a, b, bins, f) << "  (function object version)" << std::endl;
}

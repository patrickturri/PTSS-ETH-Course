/* Programming Techniques for Scientific Simulations, ETH Zürich
 */

#include "simpson.hpp"

#include <cmath>
#include <iostream>

double unit_disk(const double x, const double y)
{
    return static_cast<double>(x * x + y * y <= 1.); // don't use implicit conversion
}

double phi(const double x, const double y)
{
    return exp(-(x * x + y * y));
}

// Function object for support domain.
struct phi_wrapper
{
public:
    phi_wrapper(double R) : R2_(R * R) {}
    double operator()(const double x, const double y) const
    {
        if (x * x + y * y <= R2_)
            return phi(x, y);
        return 0.;
    }

private:
    const double R2_;
};

// Function for 2d integration in a square.
//  - type F2D must be callable
// Arguments:
//  - a,b: bounds on the x-axis, a <= b
//  - Nx:  number of integration bins in x direction
//  - c,d: bounds on the y-axis, c <= d
//  - Ny:  number of integration bins in y direction
//  - f2d: function to be integrated
template <typename T, typename F2D>
T integrate2d(T a, T b, const unsigned Nx,
              T c, T d, const unsigned Ny,
              const F2D &f2d)
{
    auto F = [&](T x) {
        return simpson(c, d, Ny, [&](T y) { return f2d(x, y); });
    };
    T I = simpson(a, b, Nx, F);
    return I;
}

int main()
{

    const double R = 1.7606;
    const unsigned int bins = 1024;

    std::cout.precision(15);

    // Check implementation by calculating pi.
    std::cout << integrate2d(-1., 1., bins, -1., 1., bins, &unit_disk)
              << std::endl;

    // Solve the problem without changing the 1D library.
    auto phiR = phi_wrapper(R);
    std::cout << integrate2d(-1., 1., bins, -1., 1., bins, phiR)
              << std::endl;

    return 0;
}

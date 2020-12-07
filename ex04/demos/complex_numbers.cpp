#include <iostream>
#include <math.h>

class Complex
{
public:
    typedef double value_t;
    Complex(value_t re = 0., value_t im = 0.) : re_(re), im_(im){}; //
    value_t re() { return re_; };
    value_t im() { return im_; };
    Complex operator+(Complex const &); // addition
    //int operator-(Complex const & )
    friend Complex operator-(Complex const &, Complex const &);

private:
    value_t re_, im_;
};

Complex operator-(Complex const &a, Complex const &b)
{
    Complex tmp = Complex(a.re_ - b.re_, a.im_ - b.im_);
    return tmp;
}

int main()
{
    // Complex::value_t c;
    // Complex a(1., 2.);
    // Complex b(3., 4.);
    // c = a + b;
    // c = a.operator+(b);
}
/* Programming Techniques for Scientific Simulations, ETH Zürich
 */

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

#include <cassert>

// general case assuming F includes "input_t"
// F must provide the type input_t
template <class F>
struct domain_t
{
    using type = typename F::input_t;
};

// special case for function pointers
template <class R, class T>
struct domain_t<R (*)(T)>
{
    using type = T;
};

// general case assuming F includes "output_t"
// F must provide the type output_t
template <class F>
struct result_t
{
    using type = typename F::output_t;
};

// special case for function pointers
template <class R, class T>
struct result_t<R (*)(T)>
{
    using type = R;
};

// Concepts for F
//  - F must be callable
// Arguments:
//  - a, b: boundary of the integration interval; required that a <= b
//  - bins: number of integration intervals
//  - func: function to be integrated
template <class F>
typename result_t<F>::type integrate(typename domain_t<F>::type a,
                                     typename domain_t<F>::type b,
                                     unsigned int bins,
                                     const F &func)
{

    assert(bins > 0);
    using domain_t = typename domain_t<F>::type;
    const domain_t dr = (b - a) / (2. * bins);
    typename result_t<F>::type I2(0), I4(0);
    domain_t pos = a;

    for (unsigned i = 0; i < bins; ++i)
    {
        pos += dr;
        I4 += func(pos);
        pos += dr;
        I2 += func(pos);
    }

    return (func(a) + 2. * I2 + 4. * I4 - func(b)) * (dr / 3.);
}

#endif

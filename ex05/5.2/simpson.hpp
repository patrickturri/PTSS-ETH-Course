/* Programming Techniques for Scientific Simulations, ETH Zürich
 */

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

#include <cassert>

// Concepts needed for type F:
//     - F needs to be a function or function object taking a single argument convertible from T,
//       with return value convertible to T.
// Concepts needed for type T:
//     - CopyConstructible
//     - Assignable
//     - T shall support arithmetic operations with double with result convertible to T with
//       limited relative truncation errors.
template <typename F, typename T>
T simpson(const T a, const T b, const unsigned bins, const F &func)
{
    assert(bins > 0);

    const T dr = (b - a) / (2. * bins);
    T I2(0), I4(0);
    T pos = a;

    for (unsigned int i = 0; i < bins; ++i)
    {
        pos += dr;
        I4 += func(pos);
        pos += dr;
        I2 += func(pos);
    }

    return (func(a) + 2. * I2 + 4. * I4 - func(b)) * (dr / 3.);
}

#endif // SIMPSON_HPP

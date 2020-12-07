/* Programming Techniques for Scientific Simulations, HS 2020
 * Exercise 4.1
 */

#include <iostream>

enum Z2
{
    Plus,
    Minus
};

// Concepts needed for type T:
//   - CopyConstructible
//   - A conversion from int to T has to exist.
//   - T(1) should act as the identity with respect to multiplication.
template <class T>
T identity_element() { return T(1); }

// Template specialization for Z2
template <>
Z2 identity_element() { return Plus; }

// Group operation
Z2 operator*(const Z2 a, const Z2 b)
{
    return (a == b ? Plus : Minus);
}

std::ostream &operator<<(std::ostream &os, const Z2 a)
{
    os << (a == Plus ? "Plus" : "Minus");
    return os;
}

// Concepts needed for type T:
//   - CopyConstructible
//   - Negation (-a) must exist and the result must be convertible to T.
template <class T>
T operator*(const T a, const Z2 b)
{
    return (b == Plus ? a : -a);
}

template <class T>
T operator*(const Z2 b, const T a)
{
    return a * b;
}

// Concepts needed for type T:
//   - CopyConstructible
//   - Assignable
//   - T identity_element<T>() shall return the identity element with respect to multiplication.
//   - Multiplication a*b must exist and the result be convertible to T.
//   - Associativity (a*b)*c=a*(b*c), in order to compute the power in logarithmic time.
template <class T>
T mypow(T a, unsigned int n)
{
    T res(identity_element<T>());
    while (n > 0)
    {
        if (n % 2 != 0)
            res = res * a;
        n /= 2;
        a = a * a;
    }
    return res;
}

int main()
{
    // Some testing: feel free to add your own!
    std::cout << "Plus*Minus = " << Plus * Minus << std::endl;
    std::cout << "Plus*-1*Minus = " << Plus * -1 * Minus << std::endl;
    std::cout << "(1.+3.)*mypow(Minus,4) = " << (1. + 3.) * mypow(Minus, 4) << std::endl;

    for (unsigned i = 0; i < 7; ++i)
        std::cout << "Plus^" << i << " = " << mypow(Plus, i) << std::endl;
    for (unsigned i = 0; i < 7; ++i)
        std::cout << "Minus^" << i << " = " << mypow(Minus, i) << std::endl;
    for (unsigned i = 0; i < 7; ++i)
        std::cout << "2^" << i << " = " << mypow(2.0, i) << std::endl;

    return 0;
}

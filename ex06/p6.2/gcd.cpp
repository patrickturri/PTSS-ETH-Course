#include <iostream>
#include "helper.hpp"
#include "is_allowed.hpp"
#include "black_magic.hpp"

template <typename T, typename wish_come_true<is_allowed<T>::value, T>::t = 0>
/* 
  PRECONDITIONS:
  - a, b are of integral type
    -  (unsigned) short
    -  (unsigned) int
    -  (unsigned) long long
  POSTCONDITIONS:
  - Returns gcd of a and b with the same integral type
  - Returns zero if a and b are zero 
*/
T gcd(T a, T b)
{
    if (a == 0)
        return b;
    while (b != 0)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main()
{
    // TODO: Uncomment for c) i)
    // std::cout << "is_allowed(40) = " << check_type(40)  << " (expected 1)" << std::endl;
    // std::cout << "is_allowed(3.0) = " << check_type(3.0)  << " (expected 0)" << std::endl;
    // TODO: Uncomment for a) and c) ii)
    std::cout << "gcd(40, 3) = " << gcd(40, 3) << std::endl;
    //std::cout << "gcd(40.0, 3.0) = " << gcd(40.0, 3.0) << std::endl;
    std::cout << "gcd(40u, 15u) = " << gcd(40u, 15u) << std::endl;
    //std::cout << "gcd(40, 3.0) = " << gcd(40, 3.0) << std::endl;
    //std::cout << "gcd(40L, 3.0) = " << gcd(40L, 3.0) << std::endl;
    //std::cout << "gcd(true, false) = " << gcd(true, false) << std::endl;
    //std::cout << "gcd('9', '3') = " << gcd('9', '3') << std::endl;
}

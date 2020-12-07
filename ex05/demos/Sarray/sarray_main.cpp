#include "sarray.hpp"
#include <iostream>

int main()
{
    std::cout << "Part 01:\n";
    {
        SArray a(2); // default ctor called
        std::cout << a[1] << "\n";
        SArray b(4);
        b[0] = 1;                  // default ctor called with size parameter
        b[1] = 2;                  // default ctor called with size parameter
        b[2] = 3;                  // default ctor called with size parameter
        b[3] = 4;                  // default ctor called with size parameter
        SArray c(b);               // copy ctor called
        SArray d = c;              // copyt ctor called
        a = b;                     // copy assignment called
        c += b;                    // c has size = 11
        std::cout << c[2] << '\n'; // random big number
        SArray const e = a + b;
        std::cout << e[0] << '\n';
    }

    std::cout << "Part 02:\n";
    {
        SArray a(2);
        a = a + a + a;
    }
}

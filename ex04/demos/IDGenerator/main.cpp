#include <iostream>
#include "IDGenerator.hpp"

int main()
{

    for (int cnt = 0; cnt < 10; ++cnt)
    {
        std::cout << "The next ID is: " << IDGenerator::getNextID() << std::endl;
    }
}

#include "IDGenerator.hpp"

// static data member definition
#if CHOICE == 0
int IDGenerator::nextID_ = IDGenerator::firstID;
#endif

int IDGenerator::getNextID()
{
    return IDGenerator::nextID_++;
}

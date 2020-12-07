#ifndef IDGenerator_HPP
#define IDGenerator_HPP

// Available choice are:
//  CHOICE == 0 : correct
//  CHOICE == 1 : fails with "non-const static data member
//                must be initialized out of line"
//  CHOICE == 2 : fails due to duplicate symbols
#define CHOICE 0

class IDGenerator
{
public:
    static int getNextID();       // static member function
    const static int firstID = 0; // const static data member
                                  // in class definition
private:
#if CHOICE == 0 || CHOICE == 2
    static int nextID_; // static data member declaration
#endif
#if CHOICE == 1
    static int nextID_; // static data member definition
#endif
};

#if CHOICE == 1
int IDGenerator::nextID_ = 0;
#endif

#if CHOICE == 2
int IDGenerator::nextID_ = IDGenerator::firstID;
#endif

#endif /* IDGenerator_HPP */

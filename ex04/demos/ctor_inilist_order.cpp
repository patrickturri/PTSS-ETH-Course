#include <iostream>

struct A
{
    A(int i) { std::cout << i << std::endl; }
};

struct B
{
    B() : one(1), two(2), three(3) {}
    // the initializer list is not in the same order as the members!
    // compiling with the option '-Wreorder' (gcc,clang)
    A one;
    A three;
    A two;
};

int main()
{
    B b;
    return 0;
}

#ifndef BLACK_MAGIC_HPP
#define BLACK_MAGIC_HPP
#include <iostream>

template <bool B, class T = void>
struct wish_come_true
{
};

// TODO uncomment and finish spezialisation part
template <class T>
struct wish_come_true<true, T>
{
    typedef T t;
};

#endif

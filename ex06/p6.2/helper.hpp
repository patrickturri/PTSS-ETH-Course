#ifndef HELPER_HPP
#define HELPER_HPP
#include "is_allowed.hpp"

template <typename T>
T check_type(T)
{
    return (is_allowed<T>::value) ? true : false;
}

#endif

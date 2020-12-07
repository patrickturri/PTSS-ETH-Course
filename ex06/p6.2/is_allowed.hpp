#ifndef IS_ALLOWED_HPP
#define IS_ALLOWED_HPP
#include <type_traits>

//typedef std::integral_constant<bool, true> true_type; // typedef is a storage-class, like 'auto'
//typedef std::integral_constant<bool, false> false_type;

template <class T>
struct is_allowed : std::false_type
{
};

// TODO add specialization for all possible types
template <>
struct is_allowed<short> : std::true_type // it's inheritence from the typedef storage class
{
};

template <>
struct is_allowed<unsigned short> : std::true_type
{
};

template <>
struct is_allowed<int> : std::true_type
{
};

template <>
struct is_allowed<unsigned int> : std::true_type
{
};

template <>
struct is_allowed<long long> : std::true_type
{
};

template <>
struct is_allowed<unsigned long long> : std::true_type
{
};

#endif

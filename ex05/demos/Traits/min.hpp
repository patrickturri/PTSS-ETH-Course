#ifndef MIN_HPP
#define MIN_HPP

template <typename T, typename U>
struct min_type
{
};

// partial specialization
template <typename T>
struct min_type<T, T>
{
    typedef T type;
};

// full specialization
template <>
struct min_type<float, double>
{
    typedef double type;
};
template <>
struct min_type<double, float>
{
    typedef double type;
};
template <>
struct min_type<float, int>
{
    typedef float type;
};
template <>
struct min_type<int, float>
{
    typedef float type;
};
template <>
struct min_type<int, int>
{
    typedef int type;
};
template <>
struct min_type<int, double>
{
    typedef double type;
};

template <typename T, typename U>
typename min_type<T, U>::type min(T const &x, U const &y)
{
    return x < y ? x : y;
}

#endif /* MIN_HPP */

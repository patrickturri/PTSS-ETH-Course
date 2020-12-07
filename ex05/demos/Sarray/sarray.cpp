#include "sarray.hpp"
#include <iostream>
#include <cassert>
#include <utility> // for std::swap

//ctors
// default
SArray::SArray() : size_(0), elem_(nullptr)
{
#ifdef VERBOSE
    std::cout << "SArray default ctor called\n";
#endif
}

// array of given size
SArray::SArray(sz_t size) : size_(size), elem_(new elem_t[size])
{
#ifdef VERBOSE
    std::cout << "SArray with size argument called\n";
#endif
}

// copy ctor
SArray::SArray(SArray const &a) : size_(a.size_), elem_(new elem_t[size_])
{
#ifdef VERBOSE
    std::cout << "SArray ctor with size argument called\n";
#endif
    // copy elements
    for (sz_t i = 0; i < size_; i++)
    {
        elem_[i] = a.elem_[i];
    }
}

// copy assignemnt
SArray &SArray::operator=(SArray const &rhs)
{
    SArray temp(rhs); // call copy ctor
    swap(temp);       // swap
    return *this;
}
#ifdef MOVE
// move ctor
SArray::SArray(SArray &&a) : size_(a.size), elem_(a.elem_)
{
#ifdef VERBOSE
    std::cout << "SArray move ctor called\n";
#endif
    a.size_ = 0;
    a.elem_ = nullptr;
}
// move assignment
SArray &SArray::operator=(SArray &&rhs)
{
#ifdef VERBOSE
    std::cout << "SArray move assignment called\n";
#endif
    swap(rhs);
    return *this;
}
#endif
// dctor
SArray::~SArray()
{
#ifdef VERBOSE
    std::cout << "SArray dtor called\n";
#endif
    delete[] elem_;
    elem_ = nullptr;
    size_ = 0;
}
// further operators
// subscript operator
SArray::elem_t &SArray::operator[](sz_t const index)
{
    assert(index < size());
    return elem_[index];
}

// const subscript operator
SArray::elem_t const &SArray::operator[](sz_t index) const
{
    assert(index < size());
    return elem_[index];
}

SArray &SArray::operator+=(SArray const &rhs)
{
    size_ += rhs.size_;
    for (sz_t i = 0; i < size_; i++)
    {
        elem_[i] += rhs.elem_[i];
    }
    return *this;
}

SArray &SArray::operator-=(SArray const &rhs)
{
    size_ -= rhs.size_;
    for (sz_t i = 0; i < size_; i++)
    {
        elem_[i] -= rhs.elem_[i];
    }
    return *this;
}

SArray &SArray::operator*=(SArray const &rhs)
{
    size_ *= rhs.size_;
    for (sz_t i = 0; i < size_; i++)
    {
        elem_[i] *= rhs.elem_[i];
    }
    return *this;
}
SArray &SArray::operator/=(SArray const &rhs)
{
    assert(size_ == rhs.size_); // check if compatible sizes!
    for (sz_t i = 0; i < size_; ++i)
    {
        elem_[i] /= rhs.elem_[i];
    }
    return *this;
}

SArray::sz_t SArray::size() const
{
    return size_;
}

void SArray::swap(SArray &other)
{
    using std::swap; // let c++ decide which swap to call!!
    swap(size_, other.size_);
    swap(elem_, other.elem_);
}

// free-function swap
void swap(SArray &a, SArray &b)
{
    a.swap(b);
}

// binary arithmetic operators
SArray operator+(SArray a, SArray const &b)
{
    a += b;
    return a;
}
SArray operator-(SArray a, SArray const &b)
{
    a -= b;
    return a;
}
SArray operator*(SArray a, SArray const &b)
{
    a *= b;
    return a;
}
SArray operator/(SArray a, SArray const &b)
{
    a /= b;
    return a;
}

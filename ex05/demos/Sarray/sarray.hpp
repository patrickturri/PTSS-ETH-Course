#ifndef SARRAY_HPP
#define SARRAY_HPP

// (Too!) Simple array class
class SArray
{
public:
    using sz_t = unsigned int; // size type
    using elem_t = double;     // element type
    // ctors
    SArray();              // default ctor: empty array
    explicit SArray(sz_t); // ctor: array of given size
                           // (explicit to avoid sarray v = 10 creating an
                           // array of size 10!)
    // copy ctor
    SArray(SArray const &);
    // copy assignment
    SArray &operator=(SArray const &);
#ifdef MOVE
    // move ctor
    SArray(SArray &&);
    // move assignment
    SArray &operator=(SArray &&);
#endif
    // dtor
    ~SArray();
    // compound arithmetic operators
    SArray &operator+=(SArray const &);
    SArray &operator-=(SArray const &);
    SArray &operator*=(SArray const &);
    SArray &operator/=(SArray const &);
    // further operators
    elem_t &operator[](sz_t const);             // subscript operator
    elem_t const &operator[](sz_t const) const; // const subscript operator
    // further utility member functions
    sz_t size() const;   // size of the array
    void swap(SArray &); // swap
private:
    sz_t size_;    // size of array
    elem_t *elem_; // pointer to (dynamic) memory of array
};

// free-function swap
void swap(SArray &, SArray &);

// binary arithmetic operators
SArray operator+(SArray, SArray const &);
SArray operator-(SArray, SArray const &);
SArray operator*(SArray, SArray const &);
SArray operator/(SArray, SArray const &);

#endif /* SARRAY_HPP */

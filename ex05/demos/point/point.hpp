#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

class Point
{
public:
    typedef double coord_t;
    // ctor
    Point(coord_t x = 0., coord_t y = 0.);
    // copy ctor
    Point(const Point &) = default;
    // destructor
    ~Point() = default;
    // copy assignment
    Point &operator=(const Point &);
    // compound and subtraction assignments
    Point &operator+=(Point const &);
    Point &operator-=(Point const &);
    // further properties and operations
    coord_t x() const;                 // x coordinate
    coord_t y() const;                 // y coordinate
    coord_t abs() const;               // distance from origin aka polar radius
    coord_t dist(const Point &) const; // distance of this point to another point
    coord_t angle() const;             // polar angle
    void invert();                     // mirror a point at origin (0,0)
private:
    coord_t x_, y_; // Cartesian coordinates
};

// pretty print of a Point by overloading the insertion operator
std::ostream &operator<<(std::ostream &, Point const &);

// binary add and substraction operator
Point operator+(Point, Point const &); // better with += OP!
// Point operator+(Point const&, Point const&); // "suboptimal"
Point operator-(Point, Point const &);

#endif
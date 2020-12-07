#include <cmath>
#include <iostream>
#include "point.hpp"

// ctor
Point::Point(coord_t x, coord_t y) : x_(x), y_(y) {}

//copy assignment

Point &Point::operator=(Point const &rhs)
{
    x_ = rhs.x_;
    y_ = rhs.y_;
    return *this;
}

// compound add & subtraction assignment
Point &Point::operator+=(Point const &rhs)
{
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
}
Point &Point::operator-=(Point const &rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}

// further properties & operations
// get x coordinate
Point::coord_t Point::x() const
{
    return x_;
}
// get y coordinate
Point::coord_t Point::y() const
{
    return y_;
}
// distance from origin aka polar radius
Point::coord_t Point::abs() const
{
    return std::sqrt(x_ * x_ + y_ * y_);
}
// distance of this point to another point
Point::coord_t Point::dist(const Point &p) const
{
    coord_t xdiff = x_ - p.x_;
    coord_t ydiff = y_ - p.y_;
    return std::sqrt(xdiff * xdiff + ydiff * ydiff);
}
// polar angle
Point::coord_t Point::angle() const
{
    return std::atan2(y_, x_);
}
// mirror a point at origin (0,0)
void Point::invert()
{
    x_ = -x_;
    y_ = -y_;
}

// pretty print of a Point by overloading the insertion operator
std::ostream &operator<<(std::ostream &out, Point const &p)
{
    out << "(" << p.x() << ", " << p.y() << ")";
    return out;
}

// binary add & subtraction operators
Point operator+(Point p1, Point const &p2)
{
    return p1 += p2;
}
// "suboptimal" implementation not using += operator!
// Point operator+(Point const& p1, Point const& p2) {
//   Point result(p1.x() + p2.x(), p1.y() + p2.y());
//   return result;
// }
Point operator-(Point p1, Point const &p2)
{
    return p1 -= p2;
}

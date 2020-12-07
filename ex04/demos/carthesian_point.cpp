#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define PI 3.14159265

class Point
{
public:
    typedef double coord_t;
    Point(coord_t x = 0., coord_t y = 0.) : x_(x), y_(y){};
    coord_t x() { return x_; };
    coord_t y() { return y_; };
    coord_t abs();   // polar radius, it's just root square of x^2 + y^2
    coord_t angle(); // polar angle
    friend ostream &operator<<(ostream &out, Point &p)
    {
        out << "( " << p.x_ << ", " << p.y_ << " )";
        return out;
    }

    friend istream &operator>>(istream &in, Point &p)
    {
        in >> p.x_ >> p.y_;
        return in;
    }

private:
    coord_t x_, y_; // cartesian coordinates
};

// istream &operator>>(istream &in, Point &p)
// {
//     in >> "( " >> p.x() >> ", " >> p.y() >> " )";
//     return in;
// }

Point::coord_t Point::abs()
{
    return sqrt(x_ * x_ + y_ * y_);
}
Point::coord_t Point::angle()
{
    return atan(y_ / x_) * 180 / PI;
}
int main()
{
    Point p3{};
    cin >> p3;
    Point p0(2., 3.);
    Point op(1., 2.);
    Point *pp1;
    Point *pp2 = new Point(3., 12.);
    Point ap1[] = {{1., 2.}, {3., 4.}};
    Point *ap2 = new Point[2]{{5., 6.}, {7., 8.}};
    pp1 = &op;
    cout << "op.x() = " << op.x() << "\n";
    cout << "pp1 -> y() = " << pp1->y() << "\n";
    cout << "*(pp2).y() = " << pp2->y() << "\n";
    cout << "ap1[0].abs() = " << ap1[0].abs() << "\n";
    cout << "ap2[1].angle() = " << ap2[1].angle() << "\n";
    cout << "p0 = " << p0 << "\n";
    cout << "p3 = " << p3 << "\n";

    // Point p1(1., 2.), p2{7., 3.14};
    // cout << "p2.x: " << p2.x() << "\n";
    // cout << "p2.y: " << p2.y() << "\n";
    // Point p3{};
}
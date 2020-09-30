#include <iostream>
#include <cmath>
#include <cassert>
#define _USE_MATH_DEFINES

double simpson_rule(double a, double b, int bins, double (*func)(double x))
{
    assert(b > a);
    assert(bins > 0);
    double delta = (b - a) / bins;
    int count = 0;
    double sum = 0;
    double x = a;
    while (count <= bins)
    {
        if (count == 0)
        {
            sum += func(x);
        }
        else if (count == bins)
        {
            sum += func(b);
        }
        else
        {
            // if the count it's even
            if (count % 2 != 0)
            {
                sum += 4 * func(x);
            }
            else
            {
                sum += 2 * func(x);
            }
        }
        x += delta;
        count++;
    }
    return sum * delta / 3;
}
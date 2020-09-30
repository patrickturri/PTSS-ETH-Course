#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <cmath>

double simpson(int bins, float a, float b);

int main()
{
    int bins = rand();
    float b = M_PI;
    float a = 0;
    double result = simpson(bins, a, b);
    std::cout << result << "\n";
}

double simpson(int bins, float a, float b)
{
    float delta = (b - a) / bins;
    int count = 0;
    float sum = 0;
    float num = a;
    while (count <= bins)
    {
        if (count == 0)
        {
            sum += sin(num);
        }
        else if (count == bins)
        {
            sum += sin(b);
        }
        else
        {
            // if the count it's even
            if (count % 2 != 0)
            {
                sum += 4 * sin(num);
            }
            else
            {
                sum += 2 * sin(num);
            }
        }
        num += delta;
        count++;
    }
    return sum * delta / 3;
}
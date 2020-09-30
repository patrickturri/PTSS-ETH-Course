#include <iostream>

int gcd_recursive(int a, int b);
int gcd_loop(int a, int b);
int main()
{
    int a = 0;
    int b = 0;
    std::cout << "Enter two positive integers: \n";
    std::cin >> a >> b;
    int gcd_r = gcd_recursive(a, b);
    int gcd_l = gcd_loop(a, b);
    std::cout
        << "The ggc of " << a << " and " << b << " is " << gcd_r << "\n";
    std::cout << "The ggc of " << a << " and " << b << " is " << gcd_l << "\n";
}

int gcd_recursive(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    else if (a > b)
    {
        return gcd_recursive(b, a % b);
    }
    else
    {
        return gcd_recursive(a, b % a);
    }
}

int gcd_loop(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}
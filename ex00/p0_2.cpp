#include <iostream>

int fib_rec(int n);
int fib_loop(int n);
int main()
{
    int n = 0;
    std::cout << "Give me a non-negative integer"
              << "\n";
    std::cin >> n;
    int res_r = fib_rec(n);
    int res_l = fib_loop(n);
    std::cout << "This is n-th number of the Fibonacci sequence: " << res_l << "\n";
    std::cout << "This is n-th number of the Fibonacci sequence: " << res_r << "\n";
}

int fib_loop(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int previous = 0;
    int current = 1;

    for (int i = 1; i < n; i++)
    {
        int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

int fib_rec(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return (fib_rec(n - 1) + fib_rec(n - 2));
    }
}
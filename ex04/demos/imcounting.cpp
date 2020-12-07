#include <iostream>

struct ImCounting
{
    ImCounting() { cnt++; }
    static int cnt;
};
// initialize count to zero
int ImCounting::cnt = 0;

int main()
{

    ImCounting a;
    ImCounting b;

    // the constructor is called two times
    // so sp cnt = 2

    std::cout << ImCounting::cnt << '\n';

    ImCounting *p = new ImCounting[9];

    std::cout << ImCounting::cnt << '\n';

    delete[] p;
}
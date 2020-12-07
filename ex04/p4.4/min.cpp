#include <iostream>
using namespace std;

template <typename T>
T minn(T x, T y)
{
    return (x < y ? x : y);
}

int main()
{
    cout << minn<char>('e', 'c') << "\n";
}
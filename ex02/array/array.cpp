#include <iostream>
#include <cstring>
#include <vector>
int main()
{
    int n_max = 10;
    int n;
    std::cout << "Select the number of values to be inserted in the sequence of numbers: \n";
    std::cin >> n;
    // initialise static array
    double arr[n_max];
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        double value;
        std::cout << "Value: ";
        std::cin >> value;
        arr[i] = value;
        sum += arr[i];
    }
    // normalise the array
    for (int i = 0; i < n; i++)
    {
        arr[i] /= sum;
    }
    // print the array in reverse order
    for (int i = n - 1; i >= 0; i--)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // aproach with dynamic array
    std::vector<double> v;
    std::cout << "Press enter 0 when you are done\n";
    double sum_2 = 0;
    for (int i = 0; i < n_max; i++)
    {
        double value;
        std::cout << "Value: ";
        std::cin >> value;
        if (value == 0)
        {
            break;
        }
        else
        {
            v.push_back(value);
            sum_2 += v[i];
            std::cout << v[i] << "\n";
        }
    }
    // normalise sequence
    for (int i = 0; i < v.size(); i++)
    {
        v[i] /= sum_2;
    }

    // print array in reverse order
    for (int i = v.size() - 1; i >= 0; i--)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}
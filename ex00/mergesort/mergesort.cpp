#include <iostream>

long mergesort(int *arr, int *temp, int leftStart, int rightEnd);
long mergeHalves(int *arr, int *temp, int leftStart, int rightEnd);

int main()
{
    int n = 5;
    // std::cout << "Tell me a positive integer n: ";
    // std::cin >> n;
    std::cout << "Random sequence of n numbers: "
              << "\n";
    int arr[5] = {2, 1, 3, 1, 2};
    for (int i = 0; i < n; i++)
    {
        // arr[i] = rand() % 10;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Sequence sorted: "
              << "\n";
    int temp[n];
    std::cout << "Inversions: " << mergesort(arr, temp, 0, (sizeof(arr) / sizeof(arr[0]) - 1)) << "\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// create a temp array to copy the halves of the original array
long mergesort(int *arr, int *temp, int leftStart, int rightEnd)
{
    long inversions = 0;
    long middle;
    if (leftStart < rightEnd)
    {
        middle = (leftStart + rightEnd) / 2;
        inversions += mergesort(arr, temp, leftStart, middle);
        inversions += mergesort(arr, temp, middle + 1, rightEnd);
        inversions += mergeHalves(arr, temp, leftStart, rightEnd);
    }
    return inversions;
}

long mergeHalves(int *arr, int *temp, int leftStart, int rightEnd)
{
    long inversions = 0;
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int size = rightEnd - leftStart + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;
    while (left <= leftEnd && right <= rightEnd)
    {
        if (arr[left] > arr[right])
        {
            inversions += (rightStart - left);
            temp[index] = arr[right];
            right++;
        }
        else
        {
            temp[index] = arr[left];
            left++;
        }
        index++;
    }
    // adding the remaining elements of the left array to the temp array
    for (int i = left; i <= leftEnd; i++, index++)
    {
        temp[index] = arr[i];
    }
    // adding the remaining elements of the right array to the temp array
    for (int i = right; i <= rightEnd; i++, index++)
    {
        temp[index] = arr[i];
    }
    // copying all the elements in the temp array back to the original array
    for (int i = 0; i < size; i++)
    {
        arr[i + leftStart] = temp[i + leftStart];
    }
    return inversions;
}
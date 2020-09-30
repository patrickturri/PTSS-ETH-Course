#include <iostream>

void mergesort(int *arr, int *temp, int leftStart, int rightEnd);
void mergeHalves(int *arr, int *temp, int leftStart, int rightEnd);
int main()
{
    int n = 7;
    // std::cout << "Tell me a positive integer n: ";
    // std::cin >> n;
    std::cout << "Random sequence of n numbers: "
              << "\n";
    int arr[7] = {7, 9, 3, 8, 0, 2, 5};
    for (int i = 0; i < n; i++)
    {
        // arr[i] = rand() % 10;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Sequence sorted: "
              << "\n";
    int temp[n];
    mergesort(arr, temp, 0, (sizeof(arr) / sizeof(arr[0]) - 1));
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// create a temp array to copy the halves of the original array
void mergesort(int *arr, int *temp, int leftStart, int rightEnd)
{
    if (leftStart >= rightEnd)
    {
        return;
    }
    int middle = (leftStart + rightEnd) / 2;
    mergesort(arr, temp, leftStart, middle);
    mergesort(arr, temp, middle + 1, rightEnd);
    mergeHalves(arr, temp, leftStart, rightEnd);
}

void mergeHalves(int *arr, int *temp, int leftStart, int rightEnd)
{
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int size = rightEnd - leftStart + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while (left <= leftEnd && right <= rightEnd)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++;
            left++;
        }
        else
        {
            temp[index] = arr[right];
            index++;
            right++;
        }
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
}
#include <iostream>
#include <chrono>
#include "Header.h"

using std::cout;
using namespace std::chrono;

// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}


// Driver code
int main()
{
    int arr1[] = { 12, 11, 13, 5, 6, 7 };
    int arr2[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Given array is \n";
    printArray(arr1, arr_size);

    auto mergeStart = high_resolution_clock::now();
    mergeSort(arr1, 0, arr_size - 1);
    auto mergeStop = high_resolution_clock::now();

    auto mergeRuntime = duration_cast<microseconds>(mergeStop - mergeStart);

    auto quickStart = high_resolution_clock::now();
    quickSort(arr2, 0, arr_size - 1);
    auto quickStop = high_resolution_clock::now();

    auto quickRuntime = duration_cast<microseconds>(quickStop - quickStart);

    cout << "\n\nMerge Sorted array is \n";
    printArray(arr1, arr_size);
    cout << "\nIn " << mergeRuntime.count() << " ms.";

    cout << "\n\nQuick Sorted array is \n";
    printArray(arr2, arr_size);
    cout << "\nIn " << quickRuntime.count() << " ms.";
    return 0;
}
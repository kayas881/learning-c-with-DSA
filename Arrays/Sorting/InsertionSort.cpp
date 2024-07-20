#include <iostream>
using namespace std;
/*
Insertion Sort is a simple sorting algorithm that builds the final sorted array one 
item at a time. It is much less efficient on large lists than more advanced algorithms
 such as quicksort, heapsort, or merge sort.*/

// The function insertionSort sorts an array of integers in ascending order.
// explaination: 
// 1. The first element in the array is considered to be sorted.
// 2. The next element is compared with the first element and placed in the correct position in the sorted array.
// 3. The next element is compared with the first two elements and placed in the correct position in the sorted array.
// 4. This process continues until the entire array is sorted.
// Time complexity: O(n^2)
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

#include <iostream>
using namespace std;

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];  // Store the value at index i in a temporary variable
    arr[i] = arr[j];    // Move the value at index j to index i
    arr[j] = temp;      // Move the value stored in temp to index j
}

// Function to partition the array around a pivot
int partition(int arr[], int l, int r) {
    int pivot = arr[r];  // Choose the last element as the pivot
    int i = l - 1;       // Index of the smaller element

    // Traverse through the array
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {  // If current element is smaller than the pivot
            i++;               // Increment index of smaller element
            swap(arr, i, j);   // Swap current element with the element at index i
        }
    }

    // Swap the pivot element with the element at index i+1
    swap(arr, i + 1, r);
    return i + 1;  // Return the partitioning index
}

// Function to perform quicksort on the array
void quickSort(int arr[], int l, int r) {
    if (l < r) {  // Base case: if the subarray has more than one element
        int pi = partition(arr, l, r);  // Partition the array and get the pivot index

        // Recursively sort elements before and after partition
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};  // Initialize the array to be sorted
    quickSort(arr, 0, 4);         // Perform quicksort on the entire array

    // Print the sorted array
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

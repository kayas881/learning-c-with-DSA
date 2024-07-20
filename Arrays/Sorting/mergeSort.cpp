#include <iostream>
using namespace std;
/*
Merge Sort is an efficient, stable, comparison-based, divide and conquer sorting 
algorithm. Most implementations produce a stable sort, meaning that the implementation
 preserves the input order of equal elements in the sorted output.
*/

// explaination:
// 1. Divide the unsorted array into n subarrays, each containing one element.
// 2. Repeatedly merge subarrays to produce new sorted subarrays until there is only one subarray remaining.
// Time complexity: O(n log n)
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//explaination:
// 1. If there is more than one element in the array, divide the array into two halves.
// 2. Recursively sort the two halves.
// 3. Merge the sorted halves.
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

#include <iostream>
using namespace std;
/*Bubble Sort: This algorithm repeatedly steps through the list, 
compares adjacent elements and swaps them if they are in the wrong order. 
The process repeats until the list is sorted.*/
int main() {
    int n; // Declare a variable to store the size of the array
    cin >> n; // Input the size of the array

    int arr[n]; // Declare an array of size n

    // Input elements into the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble sort algorithm to sort the array
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) { // If the current element is greater than the next element
                int temp = arr[j]; // Swap the elements
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Output the sorted elements of the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

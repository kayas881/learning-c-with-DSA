#include <iostream>
using namespace std;
/*
Selection Sort: This algorithm repeatedly selects the smallest (or largest) 
element from the unsorted portion and moves it to the beginning (or end).*/
int main() {
    int n; // Declare a variable to store the size of the array
    cin >> n; // Input the size of the array

    int arr[n]; // Declare an array of size n

    // Input elements into the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection sort algorithm to sort the array
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[i]) { // If the current element is smaller than the selected element
                int temp = arr[j]; // Swap the elements
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // Output the sorted elements of the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

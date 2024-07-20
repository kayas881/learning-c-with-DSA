#include <iostream>
using namespace std;
/* An array is a collection of elements of the same type stored in 
contiguous memory locations.*/

// The main function is the entry point of the program.
int main() {
    int n; // Declare a variable to store the size of the array
    cin >> n; // Input the size of the array

    int array[n]; // Declare an array of size n

    // Input elements into the array
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Output the elements of the array
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}

/*
Accessing Elements: Array elements are accessed using indices, starting from 0.
*/
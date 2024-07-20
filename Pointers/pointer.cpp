#include <iostream>
using namespace std;
// pointers in c++ are used to store the address of another variable


// int main() {
//     int a = 10;          /* Declare an integer variable a and initialize it to 10 */
//     int* aptr = &a;      /* Declare a pointer aptr and initialize it to the address of a */

//     cout << *aptr << endl;  /* Dereference aptr to get the value of a, prints 10 */
    
//     *aptr = 20;            /* Change the value of a through aptr, now a is 20 */
    
//     cout << a << endl;     /* Print the updated value of a, prints 20 */

//     return 0;
// }

// int main() {
//     int arr[] = {10, 20, 30}; /* Declare and initialize an array arr with 3 elements */
    
//     cout << arr << endl;      /* Print the base address of the array (not the elements) */

//     int* ptr = arr;           /* Initialize ptr to point to the first element of arr */

//     for (int i = 0; i < 3; i++) {
//         cout << *(arr + i) << " "; /* Print each element using pointer arithmetic */
//     }
//     cout << endl;

//     return 0;
// }



// int main() {
//     int a = 10;              /* Declare an integer variable a and initialize it to 10 */
//     int* aptr = &a;          /* Declare a pointer aptr and initialize it to the address of a */
//     int** apptr = &aptr;     /* Declare a pointer to a pointer apptr and initialize it to the address of aptr */

//     cout << **apptr << endl; /* Dereference apptr twice to get the value of a, prints 10 */
    
//     **apptr = 30;            /* Change the value of a through apptr, now a is 30 */
    
//     cout << a << endl;       /* Print the updated value of a, prints 30 */

//     return 0;
// }


// int main() {
//     int* ptr = new int;  /* Dynamically allocate memory for a single integer on the heap */
//     *ptr = 50;          /* Set the value of the allocated memory to 50 */
    
//     cout << *ptr << endl; /* Print the value stored in the allocated memory, prints 50 */
    
//     delete ptr;         /* Free the allocated memory */

//     int* arr = new int[3]; /* Dynamically allocate memory for an array of 3 integers */
    
//     for (int i = 0; i < 3; i++) {
//         arr[i] = (i + 1) * 10; /* Initialize the array with values 10, 20, 30 */
//     }
    
//     for (int i = 0; i < 3; i++) {
//         cout << arr[i] << " "; /* Print each element of the array */
//     }
//     cout << endl;
    
//     delete[] arr; /* Free the allocated memory for the array */

//     return 0;
// }

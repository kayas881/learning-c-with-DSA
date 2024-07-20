#include <iostream>
using namespace std;

// Function to implement the Sieve of Eratosthenes algorithm to find all prime numbers up to n
void PrimeSieve(int n) {
    // Array to keep track of prime status for each number
    // 0 means prime, 1 means not prime (composite)
    int prime[100] = {0};  /* Initialize the array with 0s */

    // Iterate from 2 to n to check for prime numbers
    for (int i = 2; i <= n; i++) {
        // If prime[i] is 0, it means i is a prime number
        if (prime[i] == 0) {
            // Mark all multiples of i as non-prime (starting from i*i)
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 1;  /* Set multiples of i to 1, indicating not prime */
            }
        }
    }

    // Print all prime numbers from 2 to n
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            cout << i << " ";  /* Print the number if it is still marked as prime */
        }
    }
    cout << endl;  /* Print a newline after listing all primes */
}

int main() {
    int n;  /* Declare a variable to store the user input */
    cin >> n;  /* Read the upper limit for prime numbers from user input */

    PrimeSieve(n);  /* Call the PrimeSieve function with the input value */
    
    return 0;  /* Return 0 to indicate successful execution */
}

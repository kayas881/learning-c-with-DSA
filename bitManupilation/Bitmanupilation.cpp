#include <iostream>
using namespace std;

// what is bit manipulation?
// Bit manipulation is the act of algorithmically manipulating bits or binary digits.
//  In many programming languages (C, C++, etc.), bitwise operations are used to manipulate bits.
//   Bit manipulation can be used to perform tasks such as counting the number of bits that are set or clear in a value,
//    reversing the order of bits in a value, or checking if a particular bit is set in a value.

// what is the use of bit manipulation?
// Bit manipulation is used in many algorithms and programming tasks. Some common uses of bit manipulation include:
// 1. Counting the number of bits that are set in a value (also known as the Hamming weight or population count)
// 2. Checking if a particular bit is set in a value
// 3. Setting or clearing a bit at a particular position in a value
// 4. Finding the unique number in an array where every other number appears twice
// 5. Checking if a number is a power of 2
// 6. Counting the number of 1s in the binary representation of a number
//etc...

// Get the bit value (0 or 1) at the specified position
int getBit(int n, int pos) {
    // here 1<<pos means 1 is shifted to left by pos times
    //((n & (1 << pos)) != 0) perform bitwise AND operation between n and 1<<pos and check if the result is not equal to 0
    // for example if n=5 and pos=2 then 5=101 and 1<<2=100 so 101 & 100=100 which is not equal to 0 so it will return 1
    return ((n & (1 << pos)) != 0); // If the bit is set, return 1, otherwise return 0
}

// Set the bit to 1 at the specified position
int setBit(int n, int pos) {
    return (n | (1 << pos)); // return n with the bit at position pos set to 1
}

// Clear the bit (set to 0) at the specified position
int clearBit(int n, int pos) {
    // ~ means bitwise NOT
    // for example if n=5 and pos=2 then 1<<2=100 and ~100=011 so 101 & 011=001
    int mask = ~(1 << pos); // Create a mask with 0 at position pos and 1 elsewhere
    return (n & mask);
}

// Update the bit at the specified position with the given value (0 or 1)
int updateBit(int n, int pos, int value) {
    //example: if n=5, pos=1, value=1 then 1<<1=010 and ~(010)=101 so 101 & 101=101
    int mask = ~(1 << pos);
    n = (n & mask);
    return (n | (value << pos));
}

int main() {
    cout << getBit(5, 2) << endl;   // Output: 1 (binary 101, bit at position 2 is 1)
    cout << setBit(5, 1) << endl;   // Output: 7 (binary 101 | 010 = 111)
    cout << clearBit(5, 2) << endl; // Output: 1 (binary 101 & 011 = 001)
    cout << updateBit(5, 1, 1) << endl; // Output: 7 (binary 101 updated with 1 at position 1 = 111)
    
    // Check if a number is a power of 2
    cout << ispowerof2(8) << endl; // Output: 1 (true, 8 is a power of 2)
    
    // Count the number of 1s in the binary representation of a number
    cout << getOne(19) << endl; // Output: 3 (binary 10011 has three 1s)
    
    // Find the unique number in an array where every other number appears twice
    int arr[] = {1, 2, 2, 1, 4, 5, 5};
    cout << uniqe(arr, 7) << endl; // Output: 4 (4 is the unique number)
    
    return 0;
}

// Function to check if a number is a power of 2
int ispowerof2(int n) {
    // n should be non-zero and (n & (n-1)) should be 0 for power of 2
    return (n && !(n & (n - 1)));
}

// Function to count the number of 1s in the binary representation of a number
int getOne(int n) {
    int count = 0;
    while (n != 0) {
        n = (n & (n - 1)); // Flip the rightmost set bit
        count++;
    }
    return count;
}

// Function to find a unique number in an array where every other number appears twice
int uniqe(int arr[], int n) {
    int xorsum = 0;
    for (int i = 0; i < n; i++) {
        xorsum = xorsum ^ arr[i]; // XORing all elements, duplicates cancel out
    }
    return xorsum;
}

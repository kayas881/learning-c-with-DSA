#include <iostream>
using namespace std;
/*
The Tower of Hanoi is a classic problem in computer science and mathematics. It involves moving a stack of disks from one rod to another, 
with the help of an auxiliary rod, following these rules:
1. Only one disk can be moved at a time.
2. A disk can only be placed on top of a larger disk.

*/
void towerOfHanoi(int n, char src, char dest, char helper) {
    // Base case: If there are no disks to move, return
    if (n == 0) {
        return;
    }
    
    // Move n-1 disks from source to helper using destination as the helper peg
    towerOfHanoi(n-1, src, helper, dest);
    
    // Move the nth disk from source to destination
    cout << "moved from " << src << " to " << dest << endl;
    
    // Move the n-1 disks from helper to destination using source as the helper peg
    towerOfHanoi(n-1, helper, dest, src);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // Names of rods: A, B, and C
    return 0;
}


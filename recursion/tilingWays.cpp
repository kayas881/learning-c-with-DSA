#include <iostream>
using namespace std;

/*
The tilingWays function calculates the number of ways to tile a 1xn board using 1x1 and 2x1 tiles. 
The function uses recursion to determine this number.
*/

/*
Base Cases:

n == 0: There are 0 ways to tile a board of length 0 (invalid case).
n == 1: There is 1 way to tile a board of length 1 (one vertical 1x1 tile).
Recursive Case:

To find the number of ways to tile a board of length n, consider:
Placing a 1x1 tile vertically on the board, leaving a board of length n-1.
Placing a 2x1 tile horizontally on the board, leaving a board of length n-2.
Therefore, the total number of ways is the sum of the ways to tile the board of lengths n-1 and n-2.
*/

int tilingWays(int n) {
    if (n == 0) {
        return 0; // No ways to tile a 0-length board
    }
    if (n == 1) {
        return 1; // Only one way to tile a 1-length board (a single 1x1 tile)
    }

    // Number of ways to tile a board of length n is the sum of ways to tile boards of lengths (n-1) and (n-2)
    return tilingWays(n - 1) + tilingWays(n - 2);
}

/*
For n = 3:

tilingWays(3) computes as tilingWays(2) + tilingWays(1).
tilingWays(2) computes as tilingWays(1) + tilingWays(0).
Using base cases:
tilingWays(1) = 1
tilingWays(0) = 0
So, tilingWays(2) = 1 + 0 = 1
Finally, tilingWays(3) = 1 + 1 = 2

*/
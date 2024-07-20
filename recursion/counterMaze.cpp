#include<iostream>
using namespace std;

// counterMaze function is used to count the number of ways to reach the end of the maze
/*
The counterMaze function counts the number of distinct paths from the top-left corner (0,0) to 
the bottom-right corner (n-1,n-1) of an n x n grid, where movement is only allowed right or down.
*/
int counterMaze(int n, int i, int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }

    return counterMaze(n,i+1,j) + counterMaze(n,j+1, i);
}

int main(){
    cout<<counterMaze(3,0,0)<<endl;
    return 0;
}

/*
Initial Call: counterMaze(3, 0, 0)
Moves right to (0, 1): Calls counterMaze(3, 0, 1)
Moves right to (0, 2): Calls counterMaze(3, 0, 2)
Moves right: Out of bounds.
Moves down to (1, 2): Calls counterMaze(3, 1, 2)
Moves right: Out of bounds.
Moves down to (2, 2): Calls counterMaze(3, 2, 2)
Reached destination: Returns 1.
Returns 1 from (0, 2).
Moves down to (1, 1): Calls counterMaze(3, 1, 1)
Moves right to (1, 2): Calls counterMaze(3, 1, 2) which returns 1.
Moves down to (2, 1): Calls counterMaze(3, 2, 1)
Moves right to (2, 2): Calls counterMaze(3, 2, 2) which returns 1.
Moves down: Out of bounds.
Returns 1 from (2, 1).
Returns 2 from (1, 1).
Moves down to (1, 0): Calls counterMaze(3, 1, 0)
Moves right to (1, 1): Calls counterMaze(3, 1, 1) which returns 2.
Moves down to (2, 0): Calls counterMaze(3, 2, 0)
Moves right to (2, 1): Calls counterMaze(3, 2, 1) which returns 2.
Moves down: Out of bounds.
Returns 2 from (2, 0).
Returns 4 from (1, 0).
Result
The final result for counterMaze(3, 0, 0) is 6, which is the total number of distinct paths from (0,0) to (2,2) in a 3x3 grid.
*/
#include <iostream>
using namespace std;
//explaination of backtracking:
// Backtracking is a general algorithm for finding all (or some) solutions to some computational problems,
//  notably constraint satisfaction problems, that incrementally builds candidates to the solutions, and abandons
//   a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.
//  The classic textbook example of the use of backtracking is the eight queens puzzle, that asks for all arrangements of eight chess queens on a standard chessboard so that no queen attacks any other.


// explaination:
// The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
//  For example, following is a solution for 4 Queen problem.
//  The expected output is a binary matrix which has 1s for the blocks where queens are placed. For example, following is the output matrix for above 4 queen solution.
//  { 0,  1,  0,  0}
//  { 0,  0,  0,  1}
//  { 1,  0,  0,  0}
//  { 0,  0,  1,  0}
//  The expected output is a binary matrix which has 1s for the blocks where queens are placed. For example, following is the output matrix for above 4 queen solution.
//  { 0,  1,  0,  0}
//  { 0,  0,  0,  1}
//  { 1,  0,  0,  0}
//  { 0,  0,  1,  0}


// explaination of isSafe function:
// The isSafe function checks if a queen can be placed at a given position. It checks if there is a queen in the same column or in the same row or in the same diagonal.
//  If there is a queen in the same column or in the same row or in the same diagonal, then it returns false. Otherwise, it returns true.
bool isSafe(int** arr, int x, int y, int n){
    for(int row=0;row<=x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    int row=x;
    int col=y;
    while (row>=0 && col>=0)
    {
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while (row>=0 && col<n)
    {
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    return true;
    
}

// explaination of nQueen function:
// The nQueen function is a recursive function that places queens on the chessboard. It takes the chessboard, the current row, and the size of the chessboard as input.
//  It tries to place a queen in each column of the current row. If it finds a safe position, it places the queen and calls itself recursively for the next row.
//  If it is not able to place the queen in any column of the current row, it backtracks and tries to place the queen in the next column of the previous row.
//  If it is not able to place the queen in any column of the previous row, it backtracks further and tries to place the queen in the next column of the previous row.
//  It continues this process until it is able to place all the queens on the chessboard.
//  If it is able to place all the queens, it returns true. Otherwise, it returns false.
int nQueen(int** arr, int x, int n){
    if(x>=n){
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;

            if(nQueen(arr,x+1,n)){
                return true;
            }

            arr[x] [col]=0;
        }
    }
    return false;
}

// explaination of merge function:
// The merge function merges two sorted arrays into a single sorted array. It takes the array, the starting index of the first array, the middle index, and the ending index as input.
//  It creates two temporary arrays to store the two sorted arrays. It then merges the two sorted arrays into a single sorted array.
//  It then copies the elements of the merged array back to the original array.
void merge(int arr[], int l, int mid, int r){

    int n1 = mid - l + 1;
    int n2 = r - mid;


   int a[n1];
    int b[n2];

    for(int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
        while(j<n1){
     arr[k]=b[j];
            k++;
            j++;
    }

}
// explaination of mergeSort function:
// The mergeSort function sorts an array using the merge sort algorithm. It takes the array, the starting index, and the ending index as input.
//  It divides the array into two halves and calls itself recursively for the two halves. It then merges the two sorted halves using the merge function.
//  It continues this process until the array is completely sorted.
void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid= (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

//example with array [5,3,2,5,6]
// first we divide the array into two halves [5,3,2] and [5,6]
// then we divide the first half into two halves [5] and [3,2]
// then we divide the second half into two halves [5] and [6]
// then we merge the two halves of the first half [5] and [3,2] into [2,3,5]
// then we merge the two halves of the second half [5] and [6] into [5,6]
// then we merge the two halves [2,3,5] and [5,6] into [2,3,5,5,6]

int main(){
    int n;
    cin>>n;

    int** arr = new int*[n];

    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

   if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
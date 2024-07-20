#include <iostream>
using namespace std;
// Counting sort is a sorting technique based on keys between a specific range.
// It works by counting the number of objects having distinct key values (kind of hashing).
// Then doing some arithmetic to calculate the position of each object in the output sequence.

// for example: if we have an array of size 9 and the elements are {1,3,2,3,4,1,6,4,3}
// then the output will be {1,1,2,3,3,3,4,4,6}

//explaination of code:
// 1. Take an array as input from the user.
// 2. in the countSort function, find the maximum element in the array.
// 3. Create a count array of size max+1 and initialize it with 0.
// 4. Traverse the array and increment the count of the element in the count array.
// 5. Traverse the count array and update the count of each element by adding the previous count.
// 6. Create an output array of the same size as the input array.
// 7. Traverse the input array from the end and place the elements in the output array based on the count array.
// 8. Copy the output array to the input array.
// 9. Print the sorted array.
void countSort(int arr[],int n){
    
    int k =0;
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]] =arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}


int main(){

    int arr[]={1,3,2,3,4,1,6,4,3};
    countSort(arr,9);
    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
};
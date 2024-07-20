#include <iostream>
#include <string>
using namespace std;

// recursion is a process in which a function calls itself as a subroutine
// recursion is used to solve problems that can be broken down into smaller, repetitive problems
// recursion is used to solve problems that contain smaller instances of the same problem


// here in Sum function we are adding the numbers from 1 to n
// if n is 0 then we return 0
// else we call the function Sum with n-1 and add n to the previous sum
// for example n = 5
// 5+4+3+2+1+0 = 15
//detailed execution
// Sum(5) = 5+Sum(4)
// Sum(4) = 4+Sum(3)
// Sum(3) = 3+Sum(2)
// Sum(2) = 2+Sum(1)
// Sum(1) = 1+Sum(0)
// Sum(0) = 0 reached base case
// Sum(1) = 1+0 = 1
// Sum(2) = 2+1 = 3
// Sum(3) = 3+3 = 6
// Sum(4) = 4+6 = 10
// Sum(5) = 5+10 = 15
int Sum(int n){
    if (n==0){
        return 0;
    }
    int prevSum = Sum(n-1);
    return n+prevSum;
}


// here in power function we are calculating the power of a number
// base case means the smallest instance of the problem
// if p is 0 then we return 1
// else we call the function power with n and p-1 and multiply n with the previous power
// for example n = 2, p = 3
// 2*2*2 = 8
int power(int n, int p){
    if(p==0){
        return 1;
    }

    int prevPower = power(n, p-1);
     return n*prevPower;
    
}

// here in factorial function we are calculating the factorial of a number
// if n is 0 then we return 1
// else we call the function fact with n-1 and multiply n with the previous factorial
// for example n = 5
// detailed excution of the function
// fact(5) = 5*fact(4)
// fact(4) = 4*fact(3)
// fact(3) = 3*fact(2)
// fact(2) = 2*fact(1)
// fact(1) = 1*fact(0)
// fact(0) = 1 reached base case
// fact(1) = 1*1 = 1
// fact(2) = 2*1 = 2
// fact(3) = 3*2 = 6
// fact(4) = 4*6 = 24
// fact(5) = 5*24 = 120
int fact(int n){
    if(n==0){
        return 1;
    }

    int prevFact = fact(n-1);
    return n*prevFact;
}

// here in sorted function we are checking if the array is sorted or not
// if n is 1 then we return true
// else we call the function sorted with arr+1 and n-1
// and check if the first element is less than the second element and the rest of the array is sorted
// for example arr = {1,2,3,4,5}
// detailed execution of the function
// sorted(arr,5) = arr[0]<arr[1] && sorted(arr+1,4)
// sorted(arr,4) = arr[0]<arr[1] && sorted(arr+1,3)
// sorted(arr,3) = arr[0]<arr[1] && sorted(arr+1,2)
// sorted(arr,2) = arr[0]<arr[1] && sorted(arr+1,1)
// sorted(arr,1) = true
// sorted(arr,2) = arr[0]<arr[1] && true = true
// sorted(arr,3) = arr[0]<arr[1] && true = true
// sorted(arr,4) = arr[0]<arr[1] && true = true
// sorted(arr,5) = arr[0]<arr[1] && true = true
bool sorted(int arr[], int n){
    if(n==1){
        return true;
    }
    bool restArray = sorted(arr+1, n-1);
    return (arr[0]<arr[1] && restArray);
}

// here in dec function we are printing the numbers from n to 1
// if n is 0 then we return
// else we print n and call the function dec with n-1
void dec(int n){

    if(n==0){
        return;
    }

    cout<<n<<endl;
    dec(n-1);
}

// here in inc function we are printing the numbers from 1 to n
// if n is 0 then we return
// else we call the function inc with n-1 and print n
void inc(int n){
    if(n==0){
        return;
    }
    
    inc(n-1);
    cout<<n<<endl;
}


// here in firstocc function we are finding the first occurence of a number in an array
// if i is equal to n then we return -1
// else we check if the element at i is equal to the key
// if it is then we return i
// else we call the function firstocc with i+1 and key

int firstocc(int arr[], int n, int i, int key){
    if(i==n){
        return -1;
    }

    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i+1, key );
}

int lastOcc(int arr[], int n, int i, int key){
    if(i == n){
        return -1;
    }

    int restArray = lastOcc(arr, n, i+1, key);
    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}




// here in countPath function we are counting the number of ways to reach the end of the path
// if s is equal to e then we return 1
// if s is greater than e then we return 0
// else we count the number of ways to reach the end of the path by adding the number of ways to reach the end of the path by moving 1 to 6 steps
// for example s = 0, e = 3
// detailed execution of the function
// countPath(0,3) = countPath(1,3)+countPath(2,3)+countPath(3,3)
// countPath(1,3) = countPath(2,3)+countPath(3,3)
// countPath(2,3) = countPath(3,3)
// countPath(3,3) = 1
// countPath(2,3) = 1
// countPath(1,3) = 1+1 = 2
// countPath(0,3) = 1+1+1 = 3
int countPath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count =0;
    for(int i=1; i<=6;i++){
        count+= countPath(s+i,e);
    }
    return count;
}



// in friendsParing function we are pairing the friends
// if n is 0 or 1 or 2 then we return n
// else we pair the friends by calling the function friendsParing with n-1 and n-2
int friendsParing(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }

    return friendsParing(n-1) + friendsParing(n-2)*(n-1);

}
int main(){
    cout<<friendsParing(3)<<endl;
    return 0;
}
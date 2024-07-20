#include <iostream>
using namespace std;
// character in c++ is a data type that holds one character
// char is used to store characters like letters or other symbols
// char is used to store a single character

//explaination of the code
// 1. Take a word as input from the user.
// 2. Check if the word is a palindrome or not.
// 3. If the word is a palindrome, print "word is a palindrome".
// 4. If the word is not a palindrome, print "word is not a palindrome".

//what is palindrome?
// A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).
// for example: madam, level, radar, 12321, etc.
int main(){
    int n;
    cin>>n;

    char arr[n+1];
    cin>>arr;
    bool check = 1;

    for(int i=0; i<n; i++){
        if(arr[i] != arr[n-1-i]){
            check =0;
            break;

        }
    }
    if(check==true){
        cout<<"word is a palindrome"<<endl;

    }else {
        cout<<"word is not palindrome"<<endl;
    }

    return 0;
}
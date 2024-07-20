#include <iostream>
#include <stack>
using namespace std;

// // Function to reverse a sentence

// here in reverseSentence function we are using stack to reverse the sentence
// we are pushing the words in the stack and then popping them to get the reverse order
// of the sentence
void reverseSentence(string s){

    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' '&& i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }

    // Print the words in reverse order
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

// Function to insert an element at the bottom of the stack
// here in insertAtBottom function we are using recursion to insert an element at the bottom of the stack
// we are popping the elements from the stack and then inserting the element at the bottom of the stack
// and then pushing the elements back to the stack
void insertAtBottom(stack<int> &st, int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele);

    st.push(topele);
}


// Function to reverse a stack using recursion
// here in reverse function we are using recursion to reverse the stack
// we are popping the elements from the stack and then inserting them at the bottom of the stack
// and then pushing the elements back to the stack
void reverse(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}
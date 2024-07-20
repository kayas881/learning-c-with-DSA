#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


// Function to calculate the maximum area of a histogram
int get_max_area(vector<int> a){
    int n = a.size(); // get the size of the input vector
    int ans = 0; // variable to store the maximum area
    int i = 0; // variable to iterate through the vector
    stack<int> st; // stack to store the indices of the elements

    a.push_back(0); // add a sentinel element at the end of the vector

    while(i < n){
        while(!st.empty() && a[st.top()] > a[i]){
            // if the current element is smaller than the element at the top of the stack
            int t = st.top(); // get the index of the top element
            int h = a[t]; // get the height of the top element
            st.pop(); // remove the top element from the stack

            if(st.empty()){
                // if the stack is empty, the area is the height of the top element multiplied by the current index
                ans = max(ans, h * i);
            }
            else{
                // if the stack is not empty, the area is the height of the top element multiplied by the difference between the current index and the index of the element below the top element
                int len = i - st.top() - 1;
                ans = max(ans, h * len);
            }
        }
        st.push(i); // push the current index onto the stack
        i++; // move to the next index
    }

    return ans; // return the maximum area
}
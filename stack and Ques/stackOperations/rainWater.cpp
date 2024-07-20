#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int rain_water(vector<int> a){
    stack<int> st;
    int n = a.size(), ans = 0; // Initialize stack, size of the array, and answer
    for(int i = 0; i < n; i++){ // Iterate through each bar
        while(!st.empty() && a[st.top()] < a[i]){ // Process stack until current bar is shorter than top of stack
            int cur = st.top(); // Get the top index
            st.pop(); // Remove the top index

            if(st.empty()){ // If stack is empty, break
                break;
            }
            int diff = i - st.top() - 1; // Calculate the width between the current bar and the new top
            ans += min(a[st.top()], a[i] - a[cur]) * diff; // Calculate trapped water and add to the answer
        }
        st.push(i); // Push the current index onto the stack
    }
    return ans; // Return the total trapped water
}
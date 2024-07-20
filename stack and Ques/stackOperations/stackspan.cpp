#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


// stackspan function to calculate the stock span
vector<int> stackspan(vector<int> prices){
    vector<int> ans; // vector to store the stock span
    stack<pair<int,int>> st; // stack to store the prices and their indices
    for(auto price : prices){
        int days = 1; // number of days the stock price is less than or equal to the current price
        while(!st.empty() && st.top().first <= price){
            days += st.top().second; // add the number of days to the current count
            st.pop(); // remove the top element from the stack
        }
        st.push({price, days}); // push the current price and the number of days onto the stack
        ans.push_back(days); // add the number of days to the stock span
    }
}
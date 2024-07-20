#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;            // Declare a string variable to store the input expression
    cin >> s;            // Read the expression from user input

    stack<char> st;      // Stack to keep track of operators and parentheses
    bool ans = false;   // Variable to store whether redundant parentheses are found

    for (int i = 0; i < s.size(); i++) {
        // If the current character is an operator or opening parenthesis, push it onto the stack
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            st.push(s[i]); // Push operators onto the stack
        } else if (s[i] == '(') {
            st.push(s[i]); // Push opening parentheses onto the stack
        } else if (s[i] == ')') {
            // Check for redundant parentheses
            if (st.top() == '(') {
                ans = true; // Set ans to true if there is a matching opening parentheses without any operators
            }
            // Pop operators from the stack until an opening parentheses is encountered
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                st.pop(); // Pop operators from the stack
            }
            st.pop(); // Pop the opening parentheses from the stack
        }
    }

    cout << ans << endl; // Output whether redundant parentheses were found

    return 0; // Return 0 to indicate successful execution
}

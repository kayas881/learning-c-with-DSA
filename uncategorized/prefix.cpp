#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
// what is prefix expression?
// Prefix notation is a way to write expressions where the operator comes before the operands.
// For example, the infix expression 2 + 3 can be written as + 2 3 in prefix notation.
// Similarly, the infix expression (2 + 3) * 4 can be written as * + 2 3 4 in prefix notation.
// Prefix expressions are evaluated using a stack data structure.
// The algorithm for evaluating a prefix expression is as follows:


// Function to evaluate a prefix expression
int prefixEvaluation(string s) {
    stack<int> st;

    // Iterate from the end of the string to the beginning
    for (int i = s.length() - 1; i >= 0; i--) {
        // If the character is a digit, push it onto the stack
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
        } else {
            // Pop the top two elements for the operation
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            // Perform the operation based on the current character
            switch (s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }
    // The result is the top element of the stack
    return st.top();
}

// what is postfix expression?
// Postfix notation is a way to write expressions where the operator comes after the operands.
// For example, the infix expression 2 + 3 can be written as 2 3 + in postfix notation.

// Function to evaluate a postfix expression
int postfixEvaluation(string s) {
    stack<int> st;

    // Iterate from the beginning of the string to the end
    for (int i = 0; i < s.length(); i++) {
        // If the character is a digit, push it onto the stack
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
        } else {
            // Pop the top two elements for the operation
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            // Perform the operation based on the current character
            switch (s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }
    // The result is the top element of the stack
    return st.top();
}

// Function to check if a string has valid parentheses
bool isValid(string s) {
    int n = s.size();
    stack<char> st;
    bool ans = true;

    // Iterate through each character in the string
    for (int i = 0; i < n; i++) {
        // If it's an opening bracket, push it onto the stack
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            // Check for matching opening bracket
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                ans = false;
                break;
            }
        } else if (s[i] == ']') {
            // Check for matching opening bracket
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                ans = false;
                break;
            }
        } else if (s[i] == '}') {
            // Check for matching opening bracket
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                ans = false;
                break;
            }
        }
    }
    // If the stack is not empty, it means there are unmatched opening brackets
    if (!st.empty())
        return false;

    return ans;
}

int main() {
    // Example usage of the isValid function
    string s = "{([]})";

    if (isValid(s)) {
        cout << "Valid String" << endl;
    } else {
        cout << "Invalid String" << endl;
    }

    return 0;
}

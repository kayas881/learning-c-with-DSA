#include <iostream>
#include <queue>
using namespace std;

/*
The purpose of the code is to implement a stack data structure using two queues. A stack follows the Last In First Out (LIFO) principle, 
meaning the last element added is the first one to be removed. 
This implementation uses two queues to achieve the behavior of a stack.
*/


class Stack {
    int N;               // Variable to keep track of the number of elements in the stack
    queue<int> q1;       // Primary queue for stack operations
    queue<int> q2;       // Secondary queue for assisting in stack operations

public:
    // Constructor to initialize the stack
    Stack() {
        N = 0;          // Initialize the size of the stack to 0
    }

    // Function to remove the top element from the stack
    void pop() {
        if (q1.empty()) {
            return;     // If q1 is empty, there's nothing to pop
        }

        // Move all elements except the last one from q1 to q2
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();       // Remove the last element from q1
        N--;            // Decrease the size of the stack

        // Swap q1 and q2 to restore the state
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Function to add an element to the top of the stack
    void push(int val) {
        q1.push(val);   // Add the element to q1
        N++;            // Increase the size of the stack
    }

    // Function to get the top element of the stack
    int top() {
        if (q1.empty()) {
            return -1;  // If q1 is empty, return -1 to indicate the stack is empty
        }

        // Move all elements except the last one from q1 to q2
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();  // Get the last element, which is the top of the stack
        q2.push(ans);          // Push the top element to q2

        // Swap q1 and q2 to restore the state
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;            // Return the top element
    }

    // Function to get the size of the stack
    int size() {
        return N;              // Return the number of elements in the stack
    }
};

int main() {
    Stack st;         // Create an instance of the Stack class
    st.push(1);       // Push 1 onto the stack
    st.push(2);       // Push 2 onto the stack
    st.push(3);       // Push 3 onto the stack
    cout << st.size() << endl;  // Output the size of the stack, prints 3
    st.push(4);       // Push 4 onto the stack
    cout << st.size() << endl;  // Output the size of the stack, prints 4

    return 0;         // Return 0 to indicate successful execution
}


/*

Explanation
Class Members:

int N: Keeps track of the number of elements in the stack.
queue<int> q1, q2: Two queues used to simulate stack operations.
Constructor:

Initializes the size N to 0.
pop Function:

Removes the top element of the stack.
Transfers all elements except the last one from q1 to q2.
Pops the last element from q1.
Decreases the size N.
Swaps q1 and q2 to maintain the correct order.
push Function:

Adds an element to the top of the stack by pushing it into q1.
Increases the size N.
top Function:

Returns the top element of the stack without removing it.
Transfers all elements except the last one from q1 to q2.
Retrieves the last element, which is the top.
Pushes the top element back to q2.
Swaps q1 and q2 to maintain the correct order.
size Function:

Returns the current size of the stack.
main Function:

Demonstrates the usage of the Stack class by performing push operations and printing the size of the stack.
*/
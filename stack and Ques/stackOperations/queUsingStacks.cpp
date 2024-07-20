#include <bits/stdc++.h>
using namespace std;

// This queue is implemented using two stacks
class Queue {
    stack<int> s1;  // Stack to hold incoming elements
    stack<int> s2;  // Stack to hold elements for dequeue operations

public:
    // Function to add an element to the end of the queue
    void push(int x) {
        s1.push(x);  // Push the element onto s1
    }

    // Function to remove and return the front element of the queue
    int pop() {
        // If both stacks are empty, the queue is empty
        if (s1.empty() && s2.empty()) {
            cout << "empty queue\n";
            return -1;  // Return -1 to indicate an empty queue
        }

        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());  // Push top element of s1 onto s2
                s1.pop();           // Pop the top element from s1
            }
        }

        // Pop and return the top element from s2, which is the front of the queue
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    // Function to check if the queue is empty
    bool empty() {
        // The queue is empty if both stacks are empty
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;        // Create an instance of the Queue class
    q.push(1);      // Push 1 into the queue
    q.push(2);      // Push 2 into the queue
    q.push(3);      // Push 3 into the queue

    cout << q.pop() << endl;  // Output the front element, which is 1
    cout << q.pop() << endl;  // Output the next front element, which is 2

    q.push(4);      // Push 4 into the queue

    cout << q.pop() << endl;  // Output the next front element, which is 3
    cout << q.pop() << endl;  // Output the next front element, which is 4

    cout << q.empty() << endl;  // Check if the queue is empty, should print 1 (true)

    return 0;
}

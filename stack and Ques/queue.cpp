#include <iostream>
#include <stack>
using namespace std;

// Node class to represent individual elements in the queue
class node{
    public:
    int data; // Data stored in the node
    node* next; // Pointer to the next node

    // Constructor to initialize the node with given value
    node(int val){
        data = val;
        next = NULL;
    }
};

// Queue class to implement the queue data structure
class queue{
    node* front; // Pointer to the front of the queue
    node* back; // Pointer to the back of the queue

    public:
    // Constructor to initialize an empty queue
    queue(){
        front = NULL;
        back = NULL;
    }

    // Function to add an element to the back of the queue
    void push(int x){
        node* n = new node(x); // Create a new node with the given value

        // If the queue is empty, make the new node the front and back of the queue
        if(front == NULL){
            back = n;
            front = n;
            return;
        }

        back->next = n; // Make the new node the next node of the current back
        back = n; // Update the back pointer to the new node
    }

    // Function to remove the element from the front of the queue
    void pop(){
        // If the queue is empty, print an error message and return
        if(front == NULL){
            cout << "Queue underflow" << endl;
            return;
        }

        node* todelete = front; // Store the front node in a temporary variable
        front = front->next; // Update the front pointer to the next node
        delete todelete; // Delete the front node
    }

    // Function to get the element at the front of the queue
    int peek(){
        // If the queue is empty, print an error message and return -1
        if(front == NULL){
            cout << "Queue underflow" << endl;
            return -1;
        }

        return front->data; // Return the data of the front node
    }

    // Function to check if the queue is empty
    bool empty(){
        return front == NULL; // Return true if the front pointer is NULL, indicating an empty queue
    }
};




int main(){


    return 0;
}

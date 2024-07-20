#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define n 100
/*

A stack is a container that stores elements in a last-in first-out (LIFO) order. They are implemented as a container adaptor, 
a class that uses another container class as its underlying container. The underlying container class can be a vector , deque , or a list 
*/

/**
 * @class stack
 * @brief A class that represents a stack data structure.
 * 
 * The stack class provides basic operations such as push, pop, top, and empty.
 * It uses an array to store the elements of the stack and keeps track of the top element.
 */
class stack{

    int* arr; // array to store the elements of the stack
    int top; // index of the top element

    public:
    /**
     * @brief Default constructor for the stack class.
     * 
     * The constructor initializes the stack by dynamically allocating memory for the array
     * and setting the top index to -1, indicating an empty stack.
     */
    stack(){
        arr = new int[n]; // dynamically allocate memory for the array
        top = -1; // initialize top to -1, indicating an empty stack
    }

    /**
     * @brief Pushes an element onto the stack.
     * 
     * This function adds an element to the top of the stack.
     * If the stack is full, it displays an error message and returns.
     * 
     * @param x The element to be pushed onto the stack.
     */
    void push(int x){

        if(top == n-1){ // check if the stack is full
            cout<<"stack overflow"<<endl; // display an error message
            return; // exit the function
        }

        top++; // increment top
        arr[top]=x; // store the element at the top index
    }

    /**
     * @brief Pops an element from the stack.
     * 
     * This function removes the top element from the stack.
     * If the stack is empty, it displays an error message and returns.
     */
    void pop(){
        if(top==-1){ // check if the stack is empty
            cout<<"no elements to pop"<<endl; // display an error message
            return; // exit the function
        }
        top--; // decrement top to remove the top element
    }

    /**
     * @brief Returns the top element of the stack.
     * 
     * This function returns the element at the top of the stack.
     * If the stack is empty, it displays an error message and returns -1.
     * 
     * @return The top element of the stack.
     */
    int Top(){
         if(top==-1){ // check if the stack is empty
            cout<<"no elements"<<endl; // display an error message
            return -1; // return -1 as an indicator of an empty stack
        }

        return arr[top]; // return the element at the top index
    }

    /**
     * @brief Checks if the stack is empty.
     * 
     * This function checks if the stack is empty.
     * It returns true if the top index is -1, indicating an empty stack.
     * 
     * @return True if the stack is empty, false otherwise.
     */
    bool empty(){
        return top==-1; // return true if top is -1, indicating an empty stack
    }
};


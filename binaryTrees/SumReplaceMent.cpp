#include <iostream>   // For standard I/O operations
#include <vector>     // For using std::vector
#include <string>     // For using std::string
#include <map>        // For using std::map
#include <set>        // For using std::set
#include <algorithm>  // For using algorithms like sort, find, etc.
#include <utility>    // For using std::pair and other utility functions
using namespace std;


#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;               // Stores the data value of the node
    struct Node* left;      // Pointer to the left child node
    struct Node* right;     // Pointer to the right child node

    // Constructor to initialize a node with a given value
    Node(int val){
        data = val;
        left = NULL;        // Initialize left child to NULL
        right = NULL;       // Initialize right child to NULL
    }
};
// function to replace the value of each node with the sum of its children
void sumReplace(Node* root){

    if(root == NULL){ // Base case: if the node is NULL, return
        return;
    }
    sumReplace(root->left); // Recur on the left subtree
    sumReplace(root->right); // Recur on the right subtree
    if(root->left != NULL){ // If left child exists, add its value to the current node's value
        root->data += root->left->data; 
    }
    if(root->right != NULL){ // If right child exists, add its value to the current node's value
        root->data += root->right->data; 
    }
}
// function to perform preorder traversal of the binary tree
void preorder(struct Node* root){

    // Base case: if the node is NULL, return
    if(root == NULL){
        return;
    }
    
    // Visit the root node and print its data
    cout << root->data << " ";
    
    // Recur on the left subtree
    preorder(root->left);
    
    // Recur on the right subtree
    preorder(root->right);
}


int main(){

    // Creating the root node with value 1
    struct Node *root = new Node(1);
    
    // Adding child nodes
    root->left = new Node(2);             // Left child of root
    root->right = new Node(3);            // Right child of root
    root->left->left = new Node(4);       // Left child of node with value 2
    root->left->right = new Node(5);      // Right child of node with value 2
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // Performing sum replacement on the binary tree
    preorder(root);
    cout<<"\n";
    sumReplace(root);
    preorder(root);
    cout<<"\n";
    
    return 0;

    /*
        The binary tree structure is:
        
             1
           /   \
          2     3
         / \   
        4   5 
    */
}
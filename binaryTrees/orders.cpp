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

// Function to perform preorder traversal of the binary tree
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
// Function to perform inorder traversal of the binary tree
void inorder(struct Node* root){

    // Base case: if the node is NULL, return
    if(root == NULL){
        return;
    }
    
    // Recur on the left subtree
    inorder(root->left);
    
    // Visit the root node and print its data
    cout << root->data << " ";
    
    // Recur on the right subtree
    inorder(root->right);
}

// Function to perform postorder traversal of the binary tree
void postorder(struct Node* root){

    // Base case: if the node is NULL, return
    if(root == NULL){
        return;
    }
    
    // Recur on the left subtree
    postorder(root->left);
    
    // Recur on the right subtree
    postorder(root->right);

    // Visit the root node and print its data
    cout << root->data << " ";
}
int main(){
    // Creating the root node with value 1
    struct Node *root = new Node(1);
    
    // Adding child nodes
    root->left = new Node(2);             // Left child of root
    root->right = new Node(3);            // Right child of root
    root->left->left = new Node(4);       // Left child of node with value 2
    root->left->right = new Node(5);      // Right child of node with value 2
    root->right->left = new Node(6);      // Left child of node with value 3
    root->right->right = new Node(7);     // Right child of node with value 3

    // Performing preorder traversal of the binary tree
    // preorder(root);

    // Performing inorder traversal of the binary tree
    // inorder(root);

    // Performing postorder traversal of the binary tree
    postorder(root);
    
    return 0;

    /*
        The binary tree structure is:
        
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
}

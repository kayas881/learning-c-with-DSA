#include <iostream>   // For standard I/O operations
#include <vector>     // For using std::vector
#include <string>     // For using std::string
#include <map>        // For using std::map
#include <set>        // For using std::set
#include <algorithm>  // For using algorithms like sort, find, etc.
#include <utility>    // For using std::pair and other utility functions
#include <queue>      // For using std::queue
using namespace std;


// level order traversal of a binary tree
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

  /*
    structure of the binary tree:
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */
// Function to count the number of nodes in a binary tree
 int countNodes(Node* root){
        if(root == NULL){
            return 0;
        }

        // Recursively count the number of nodes in the left and right subtrees
     return countNodes(root->left) + countNodes(root->right) + 1;
 }
 
// function for sum all the nodes in a binary tree
    int sumNodes(Node* root){
        if(root == NULL){
            return 0;
        }

        // Recursively sum the nodes in the left and right subtrees
     return sumNodes(root->left) + sumNodes(root->right) + root->data;
    }

int main(){
     // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

  cout<<"Number of nodes in the binary tree: "<<countNodes(root)<<endl;
  cout<<"Sum of all nodes in the binary tree: "<<sumNodes(root)<<endl;
    return 0;

}
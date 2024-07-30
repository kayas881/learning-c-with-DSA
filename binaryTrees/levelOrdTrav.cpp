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

// Function to perform level order traversal of the binary tree
void printLevelOrder(Node* root){
    // Base case: if the node is NULL, return
    if(root == NULL){
        return;
    }
//     Create a queue to store the nodes of the binary tree
    queue<Node*> q;
    q.push(root);
    // Push a NULL node to mark the end of the current level
    q.push(NULL);

    // Loop until the queue is empty
    while(!q.empty()){
        // Get the front element of the queue
        Node* node = q.front();
        q.pop();
        // If the node is NULL, it means the current level has been traversed
        if(node != NULL){
            // Print the data of the current node
            cout<<node->data<<" ";
            if(node->left){ // If the left child exists, push it to the queue
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
           // If the queue is not empty, push a NULL node to mark the end of the current level
            else if(!q.empty()){
                q.push(NULL);
            }
        }
    }
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

    // Perform level order traversal of the binary tree
    cout<<"Level Order Traversal: ";
    printLevelOrder(root);

    return 0;
}
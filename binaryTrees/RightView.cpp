#include <iostream>   // For standard I/O operations
#include <vector>     // For using std::vector
#include <string>     // For using std::string
#include <map>        // For using std::map
#include <set>        // For using std::set
#include <algorithm>  // For using algorithms like sort, find, etc.
#include <utility>    // For using std::pair and other utility functions
#include <queue>      // For using std::queue
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

void rightView(Node* root){ 
    if(root == NULL){
        return;
    }

    queue<Node*> q; // Queue to store the nodes of the tree 
    q.push(root);

    while(!q.empty()){ // While the queue is not empty
        int n = q.size(); // Number of nodes at the current level
        for(int i=0; i<n; i++){ // Traverse all the nodes at the current level
            Node* curr = q.front(); // Get the front element of the queue
            q.pop(); // Remove the front element from the queue
            if(i == n-1){ // If the current node is the last node at the current level
                cout<<curr->data<<" "; // Print the data of the current node
            }
            if(curr->left != NULL){ // If the left child of the current node is not NULL
                q.push(curr->left); // Push the left child of the current node to the queue
            }
            if(curr->right != NULL){ // If the right child of the current node is not NULL
                q.push(curr->right); // Push the right child of the current node to the queue
        }
    }

   
}
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
 
    rightView(root); // Function to print the right view of the binary tree
    
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

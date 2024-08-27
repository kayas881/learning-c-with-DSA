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

void leftView(Node* root) {
    // Base case: If the tree is empty, return immediately.
    if (root == NULL) {
        return;
    }

    // Create a queue for level-order traversal and enqueue the root node.
    queue<Node*> q;
    q.push(root);

    // Loop until the queue is empty, meaning all levels have been processed.
    while (!q.empty()) {
        // Get the number of nodes at the current level (i.e., size of the queue).
        int n = q.size();

        // Iterate over all nodes at the current level.
        for (int i = 1; i <= n; i++) {
            // Remove the front node from the queue.
            Node* temp = q.front();
            q.pop();

            // If this is the first node in the current level, print its value.
            // This ensures only the leftmost node is printed for each level.
            if (i == 1) {
                cout << temp->data << " ";
            }

            // Enqueue the left child if it exists.
            if (temp->left != NULL) {
                q.push(temp->left);
            }

            // Enqueue the right child if it exists.
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

    /*
        The binary tree structure is:        
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */



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

    leftView(root); // Function to print the left view of the binary tree
 
    return 0;


}
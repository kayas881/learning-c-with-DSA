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
int sumAtK(Node* root, int k) {
    if (root == NULL) {
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level
    int level = 0;
    int sum = 0;

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node != NULL) {
            if (level == k) {
                sum += node->data;
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        } else if (!q.empty()) {
            q.push(NULL); // Marker for next level
            level++;
        }
    }

    return sum;
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
    // tree structure
    /*     1
    //     / \
    //    2   3
    //   / \ / \
    //  4  5 6  7 */ 
cout<<sumAtK(root, 1);
    

    return 0;
}
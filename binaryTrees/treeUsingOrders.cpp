#include "bits/stdc++.h"
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
// Build Tree from Preorder and Inorder

Node* buildTree(int preorder[], int inorder[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    static int idx = 0; // Keeps track of the current index in preorder array
    int curr = preorder[idx]; // Get the current node's value from preorder array
    idx++; // Move to the next index in preorder array

    Node* node = new Node(curr); // Create a new node with the current value

    if (start == end) {
        return node; // If this is a leaf node, return it
    }

    // Find the position of the current node in inorder array
    int pos = -1;
    for (int i = start; i <= end; i++) {
        if (inorder[i] == curr) {
            pos = i;
            break;
        }
    }

    // Recursively build the left and right subtrees
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

// Build Tree Postorder and Inorder
Node* buildTreePostorder(int postorder[], int inorder[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    static int idx = 4; // Keeps track of the current index in postorder array
    int curr = postorder[idx]; // Get the current node's value from postorder array
    idx--; // Move to the next index in postorder array

    Node* node = new Node(curr); // Create a new node with the current value

    if (start == end) {
        return node; // If this is a leaf node, return it
    }

    // Find the position of the current node in inorder array
    int pos = -1;
    for (int i = start; i <= end; i++) {
        if (inorder[i] == curr) {
            pos = i;
            break;
        }
    }

    // Recursively build the right and left subtrees
    node->right = buildTreePostorder(postorder, inorder, pos + 1, end);
    node->left = buildTreePostorder(postorder, inorder, start, pos - 1);

    return node;
}

int main() {
    // int preorder[] = {1, 2, 4, 3, 5};
    // int inorder[] = {4, 2, 1, 5, 3};

    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    Node* root = buildTreePostorder(postorder, inorder, 0, 4);

    // Node* root = buildTree(preorder, inorder, 0, 4);

    //add a function to print the tree and verify the structure
    
    
    return 0;
}
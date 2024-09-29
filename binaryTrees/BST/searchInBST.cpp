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

Node* searchInBST(Node* root, int key){

    if(root == NULL){
        return NULL;
    }
    // we will first search if the root (the current root we are on) is equal to the key or not,
    // if it is equal to the root then we will just return the root
    if(root->data == key){
        return root;
    }
    // now we will check if the root->data is greater than the key them we will discard the right tree of the root
    // and search root->left
    if(root->data > key){
        return searchInBST(root->left, key);
    }

    // similarly if the root-> data is less than key, we will then only search in the root->right
    return searchInBST(root->right, key);

}

// inorder succ

// Function to find the inorder successor (the smallest node in the right subtree)
Node* inorderSucc(Node* root) {
    Node* curr = root;
    // Loop to find the leftmost node in the right subtree
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

// Function to delete a node from the BST
Node* deleteInBST(Node* root, int key) {
    // Base case: if root is NULL, return NULL
    if (root == NULL) {
        return root;
    }

    // Searching for the node to delete (similar to search in BST)
    if (key < root->data) {
        // Key is smaller, go to the left subtree
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data) {
        // Key is greater, go to the right subtree
        root->right = deleteInBST(root->right, key);
    }
    else {
        // Node to be deleted is found
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            // No left child, replace the node with its right child
            Node* temp = root->right;
            free(root); // Free the memory of the node
            return temp;
        }
        else if (root->right == NULL) {
            // No right child, replace the node with its left child
            Node* temp = root->left;
            free(root); // Free the memory of the node
            return temp;
        }

        // Case 3: Node with two children
        // Find the inorder successor (smallest in the right subtree)
        Node* temp = inorderSucc(root->right);

        // Replace the current node's data with the inorder successor's data
        root->data = temp->data;

        // Delete the inorder successor (it will be in the right subtree)
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}


void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data<< " ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);


// if(searchInBST(root, 5) == NULL){
//     cout<< "Key doesn't exist" ;
// } else {
//     cout<< "key exists!!";
// }
inorder(root);
cout<< endl;
root = deleteInBST(root, 5);
inorder(root);
cout<<endl;

    return 0;
}
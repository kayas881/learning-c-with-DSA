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
/*
    The flatten function converts a binary tree into a linked list in place. 
    The linked list follows the pre-order traversal of the tree.

    How it works:
    1. Start from the root node.
    2. If the node has a left child, flatten the left subtree first.
    3. Move the flattened left subtree to the right of the current node.
    4. Attach the original right subtree to the end of this new right subtree.
    5. Set the left child to NULL.
    6. Repeat the process for the right subtree.
    7. The tree is flattened in pre-order (root -> left -> right).

    Example:
    Original Tree:
        1
       / \
      2   3
     / \ / \
    4  5 6  7         

    After flattening:
    1 -> 2 -> 4 -> 5 -> 3 -> 6 -> 7
*/

void flatten(Node* root){

    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->left != NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
        
    }

    flatten(root->right);
}

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
int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    flatten(root);
    inorder(root);
    cout << endl;
    

    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7         
    */

    return 0;
}
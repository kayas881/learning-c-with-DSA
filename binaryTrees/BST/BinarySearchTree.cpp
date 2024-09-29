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

Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }

    return root;
}
/*
  insertBST Function:
  -------------------
  - This function inserts a value into a Binary Search Tree (BST).
  - If the root is NULL, a new node with the value is created and returned. 
    This happens when the tree is empty or when a new value is inserted as a leaf node.
  - If the value is less than the root's data, the function recursively inserts the value into the left subtree.
  - If the value is greater than or equal to the root's data, the function recursively inserts it into the right subtree.
  - Finally, the root is returned after the insertion.

  Example Insertion Process:
  --------------------------
  For the sequence of insertions: 5, 1, 3, 4, 2, 7, the BST structure would be:

        5
       / \
      1   7
       \
        3
       / \
      2   4

  inOrder Traversal:
  ------------------
  - This function (assumed to be implemented) prints the tree values in sorted order.
  - It recursively visits the left subtree, prints the root, and then visits the right subtree.
  - In-order traversal of the above tree would print: 1 2 3 4 5 7
*/

void inOrder (Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    // Creating the root node with value 1
   Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    inOrder(root);
    cout << endl;
 
    return 0;


}


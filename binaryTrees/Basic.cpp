#include "bits/stdc++.h"
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

/**
 * The main function is the entry point of the program.
 * It creates a binary tree and performs some operations on it.
 *
 * @return 0 indicating successful execution of the program.
 */
int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    /*
        1
       / \
      2   3
    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
        1
       / \
      2   3
     / \
    4   5
    */

    return 0;
}
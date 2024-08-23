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


// this function is used to calculate the height of the tree
// it takes a node as an argument and returns the height of the tree
// if the node is NULL, it returns 0
// otherwise, it calculates the height of the left and right subtree
// and returns the maximum of the two heights + 1
int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}


// this function is used to check if the tree is balanced or not
// it takes a node as an argument and returns a boolean value
// if the node is NULL, it returns true
// otherwise, it checks if the left and right subtrees are balanced
// if they are balanced, it calculates the height of the left and right subtrees
// and checks if the difference between the heights is less than or equal to 1
// if it is, it returns true, otherwise, it returns false
bool isBalanced(Node* root){

    if(root == NULL){
        return true;
    }

    if(isBalanced(root->left) == false){
        return false;
    } 
    if(isBalanced(root->right) == false){
        return false;
    } 

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <= 1){
        return true;
    } else {
        return false;
    }

}


/*
      tree structure
            1
           / \
          2   3
         / \ / \
        4  5 6  7


*/

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if(isBalanced(root)){
        cout << "The tree is balanced" << endl;
    } else {
        cout << "The tree is not balanced" << endl;
    }

    return 0;
}
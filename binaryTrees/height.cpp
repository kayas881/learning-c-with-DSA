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
// function to find the height of a binary tree
int height(Node* root){
    if(root == NULL){ // if the root is NULL, return 0
        return 0;
    }
    int lHeight = height(root->left); // find the height of the left subtree
    int rHeight = height(root->right); // find the height of the right subtree
    return max(lHeight, rHeight) + 1; // return the maximum of the two heights + 1
}
//The diameter of a binary tree is defined as the number of nodes on the 
//longest path between any two nodes in the tree.
// function to find the diameter of a binary tree
int diameter(Node* root) {
    if(root == NULL) { // Base case: if the tree is empty, diameter is 0
        return 0;
    }

    // Calculate the height of the left and right subtrees
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    // Calculate the diameter of the left and right subtrees
    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    // The diameter that passes through the current node is lHeight + rHeight + 1
    int rootDiameter = lHeight + rHeight + 1;

    // The overall diameter is the maximum of:
    // 1. The diameter passing through the root
    // 2. The diameter of the left subtree
    // 3. The diameter of the right subtree
    return max(rootDiameter, max(lDiameter, rDiameter));
}

int calcDiameter(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(root->left, &lh);
    int rDiameter = calcDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

// Time complexity: O(n), where n is the number of nodes in the binary tree
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

/*          1
//         / \
//        2   3
//       / \ / \
//      4  5 6  7 */

    cout << height(root) << endl;
    cout << diameter(root) << endl;

    int height = 0;
    cout << calcDiameter(root, &height) << endl;
    return 0;
}
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

// Function: printSubTreeNodes
// Purpose: Prints all nodes that are exactly `k` steps away from the given `root` node.
// - If `root` is NULL or `k` is negative, the function does nothing.
// - If `k == 0`, it means we're exactly `k` steps away, so the node's data is printed.
// - Otherwise, the function recursively calls itself for the left and right subtrees, reducing `k` by 1 each time.
void printSubTreeNodes(Node* root, int k){
    if(root == NULL || k < 0){
        return;
    }
    if(k == 0){
        cout << root->data << " ";
        return;
    }
     
    printSubTreeNodes(root->left, k-1);
    printSubTreeNodes(root->right, k-1);
}

// Function: printNodesAtK
// Purpose: Finds and prints all nodes that are `k` steps away from the `target` node in the binary tree.
// - If the `root` is NULL, the function returns -1, indicating that the target node is not found.
// - If the `root` is the target node, it prints all nodes in the subtree of `target` that are `k` steps away.
//   - It then returns 0, as the target node is 0 steps away from itself.
// - The function recursively searches in the left and right subtrees to find the target node and calculate the distance (`dl` or `dr`) from the target to the current node.
//   - If the target node is found in the left subtree (`dl != -1`):
//     - If the distance from the target node plus one equals `k`, it prints the current node's data.
//     - Otherwise, it checks the right subtree to find nodes that are `k - dl - 2` steps away from the current node.
//     - The function then returns `1 + dl`, which is the distance from the target node to the current node.
//   - Similarly, if the target node is found in the right subtree (`dr != -1`):
//     - If the distance from the target node plus one equals `k`, it prints the current node's data.
//     - Otherwise, it checks the left subtree to find nodes that are `k - dr - 2` steps away from the current node.
//     - The function then returns `1 + dr`.
// - If the target node is not found in either subtree, the function returns -1.
int printNodesAtK(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printSubTreeNodes(root, k);
        return 0;
    }

    int dl = printNodesAtK(root->left, target, k);
    if(dl != -1){
        if(dl + 1 == k){
            cout << root->data << " ";
        }else{
            printSubTreeNodes(root->right, k-dl-2);
        }
        return 1 + dl;
    } 

    int dr = printNodesAtK(root->right, target, k);
    if(dr != -1){
        if(dr + 1 == k){
            cout << root->data << " ";
        }else{
            printSubTreeNodes(root->left, k-dr-2);
        }
        return 1 + dr;
    }
    return -1;
}






    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7         
    */


int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    printNodesAtK(root, root->left, 1);
    cout << endl;


    return 0;
}
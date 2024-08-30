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
Step-by-Step Execution for LCA:

Starting at the root (1):
root->data is neither 4 nor 5, so we proceed to check its left and right subtrees.

Move to left child (2):
root->data is neither 4 nor 5, so we proceed further down.

Move to left child (4):
Now, root->data matches n1 (4). This means we’ve found one of the nodes, 
so return this node (4).

Move to right child of 2 (5):
Now, root->data matches n2 (5). This means we’ve found 
the other node, so return this node (5).


Now, back at node 2, we have results from both left (4) and right (5) subtrees. 
Since both are non-NULL, the current node 2 is the LCA of nodes 4 and 5.



*/

Node* LCA(Node *root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL){
    return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left != NULL){
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

/*
Step-by-Step Execution for findDist:

From LCA (2) to 4:

Start at node 2 with dist = 0.
Move to left child (4), increase dist to 1.
Node 4 is found, return distance 1.
From LCA (2) to 5:

Start at node 2 with dist = 0.
Move to right child (5), increase dist to 1.
Node 5 is found, return distance 1.
Result: The distances are 1 from 2 to 4 and 1 from 2 to 5.
*/
int findDist(Node* root, int k, int dist){
    if(root == NULL){
        return -1;
    }
    if(root->data == k){
        return dist;
    }
    int left = findDist(root->left, k, dist + 1);
    if(left != -1){
        return left;
    }
    return findDist(root->right, k, dist + 1);
}


/*
Step-by-Step Execution for distBtwNodes:

Find the LCA:

The LCA of 4 and 5 is 2 (as determined earlier).
Calculate distances:

Distance from 2 to 4 is 1.
Distance from 2 to 5 is 1.
Add the distances:

Total distance = 1 + 1 = 2.
Final Result: The distance between nodes 4 and 5 is 2.

*/
int distBtwNodes(Node* root, int n1, int n2){
    Node *lca = LCA(root, n1, n2);
    
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
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
    root->right->right = new Node(5);      // Right child of node with value 2
    cout <<distBtwNodes(root, 4, 5) << endl; // Function to print the distance between two nodes
    return 0;


}


/*
Summary
LCA: Finds the common ancestor of two nodes.
findDist: Measures how far a node is from another node (like the LCA).
distBtwNodes: Combines the above to calculate the distance between two nodes.
*/
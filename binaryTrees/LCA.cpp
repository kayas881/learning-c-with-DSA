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

// Function to find the path from root to a given node (key)
// The path is stored in the vector `path`, which is passed by reference to avoid unnecessary copying
// Returns true if the path is found, otherwise false
bool getPath(Node* root, int key, vector<int> &path) {
    // Base case: If the root is NULL, the node doesn't exist in this subtree
    if (root == NULL) {
        return false;
    }

    // Add the current node's data to the path
    path.push_back(root->data);

    // If the current node is the target node (key), return true
    if (root->data == key) {
        return true;
    }

    // Recursively check the left and right subtrees
    // If the target node is found in either subtree, return true
    if (getPath(root->left, key, path) || getPath(root->right, key, path)) {
        return true;
    }

    // If the target node is not found in this path, backtrack by removing the current node from the path
    path.pop_back();
    return false;
}

// Function to find the Lowest Common Ancestor (LCA) of two nodes (n1, n2)
// The LCA is the deepest node that is an ancestor of both n1 and n2
// Returns the data of the LCA if found, otherwise returns -1
int LCA(Node* root, int n1, int n2) {
   // Base case: If the root is NULL, return -1
   if (root == NULL) {
       return -1;
   }

   // Vectors to store the paths from root to n1 and n2
   vector<int> path1, path2;

   // Find the paths to n1 and n2; if either is not found, return -1
   if (!getPath(root, n1, path1) || !getPath(root, n2, path2)) {
       return -1;
   }

   // Compare the paths to find the last common node
   int pc;
   for (pc = 0; pc < path1.size() && pc < path2.size(); pc++) {
       // Stop at the first point where the paths diverge
       if (path1[pc] != path2[pc]) {
           break;
       }
   }

   // The last common node before the paths diverged is the LCA
   return path1[pc - 1];
}

/*
    This approach (LCA2) is more efficient than the previous path-based method for finding the Lowest Common Ancestor (LCA) due to several reasons:

    1. Time Complexity:
       - The LCA2 approach only traverses the tree once, resulting in an O(N) time complexity.
       - The path-based approach requires multiple traversals (O(N) for each path), making it less efficient.

    2. Space Complexity:
       - LCA2 uses O(H) space, where H is the height of the tree (typically less than N).
       - The path-based approach requires O(N) space for storing paths, which can be significant in large trees.

    3. Simplicity:
       - The LCA2 approach is more elegant and concise, using recursion to naturally find the LCA without extra data structures.
       - The path-based approach is more complex, involving multiple traversals and comparisons.

    4. Practical Performance:
       - LCA2 performs better in real-world scenarios due to reduced tree traversals and lower memory usage.
       - The path-based approach can be slower and more resource-intensive.

    Summary:
       - LCA2 is preferred for its efficiency, simplicity, and practicality, especially in large trees or when performance is crucial.
*/


Node* LCA2(Node* root, int n1, int n2) {
    // Base case: If the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the current node is either n1 or n2, return the current node
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    // Recursively check the left and right subtrees
    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    // If both the left and right subtrees have an LCA, the current node is the LCA
    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    // Otherwise, return the non-NULL subtree's LCA (if it exists)
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    // tree structure
    /*        1
    //       / \
    //      2   3
    //     /   / \
    //    4   5   6
    //       /
    //      7
*/  



int n1 = 7, n2 = 6;
      int lca = LCA(root, n1, n2);

      if(lca == -1){
          cout<<"LCA does not exist"<<endl;
        }else{
            cout<<"LCA: "<<lca<<endl;
        }

return 0;

}


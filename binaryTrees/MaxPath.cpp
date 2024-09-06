//Max Sum Path from One Node to Another in Binary Tree#include <iostream>   // For standard I/O operations
#include <vector>     // For using std::vector
#include <string>     // For using std::string
#include <map>        // For using std::map
#include <set>        // For using std::set
#include <algorithm>  // For using algorithms like sort, find, etc.
#include <utility>    // For using std::pair and other utility functions
#include <queue>      // For using std::queue
#include <stack>      // For using std::stack
#include <climits>
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
This code calculates the maximum path sum in a binary tree, where a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.

Key Functions:
1. maxPathSumUtil(Node* root, int &ans):
   - This is the utility function that recursively computes the maximum path sum.
   - It returns the maximum possible sum of paths that pass through the current node and can extend to its parent.
   - It also updates the overall maximum path sum (ans) for the entire tree.

   Steps:
   - If the root is NULL, return 0 (base case for recursion).
   - Recursively find the maximum path sums for the left and right subtrees.
   - Calculate the maximum possible path sum at the current node (`nodeMax`):
     1. The node alone.
     2. The node + left subtree + right subtree.
     3. The node + left subtree.
     4. The node + right subtree.
   - Update the overall maximum path sum (`ans`) to store the highest sum encountered so far.
   - Return the maximum sum of paths that can continue through the current node (`singlePathSum`), which can either be:
     1. The node alone.
     2. The node + left subtree.
     3. The node + right subtree.

2. maxPathSum(Node* root):
   - This is the main function that initializes the answer (`ans`) to a very small value (`INT_MIN`).
   - It calls maxPathSumUtil to compute the maximum path sum and returns the result.

### Example Tree:
          10
         /  \
        2    10
       / \     \
      20  1    -25
               /  \
              3    4

### Explanation of maxPathSumUtil for the example tree:
- The function is called recursively on all nodes of the tree.
- For each node, the maximum path sum through that node is calculated, and the overall maximum path sum (`ans`) is updated.

1. **Leaf nodes (3, 4, 1, 20)**: 
   - Each of these nodes returns its own value since they have no children.
   - The maximum path sum at each leaf node is simply its value.

2. **Node -25**:
   - The left child is 3, and the right child is 4. The max path sum for the left and right children is 3 and 4, respectively.
   - So, the max path sum through node -25 is:
     - `-25 + 3 + 4 = -18` (path going through both children).
   - The function returns `-25 + max(3, 4) = -21`, which is the maximum path sum for node -25 that can extend to its parent.

3. **Right subtree root (10)**:
   - The left subtree (NULL) returns 0, and the right subtree (-25) returns -21.
   - The max path sum through this node is:
     - `10 + (-21) = 10`.
   - The function returns `10`, since that’s the maximum possible sum for this node.

4. **Left subtree root (2)**:
   - The left child is 20, and the right child is 1. The max path sum for the left and right children is 20 and 1, respectively.
   - So, the max path sum through node 2 is:
     - `2 + 20 + 1 = 23` (path going through both children).
   - The function returns `2 + max(20, 1) = 22`, which is the maximum path sum for node 2 that can extend to its parent.

5. **Root (10)**:
   - The left subtree (2) returns 22, and the right subtree (10) returns 10.
   - The max path sum through the root is:
     - `10 + 22 + 10 = 42` (path going through both children).
   - The function returns `10 + max(22, 10) = 32`, which is the maximum path sum extending through the root.

### Overall Maximum Path Sum:
- The maximum path sum for the entire tree is 42, which comes from the path: `20 → 2 → 10 (root) → 10 → -25 → 3`.

*/

int maxPathSumUtil(Node *root, int &ans){

    if(root == NULL){
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), 
    max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    return singlePathSum;
}

int maxPathSum(Node *root){

    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main(){
     // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

 
    return 0;

}
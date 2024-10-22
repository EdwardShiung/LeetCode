#include <iostream>
using namespace std;


/*
You are given the root of a binary tree. 
We install cameras on the tree nodes where each camera at a node can monitor its parent, 
itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:

Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.


Example 2:

Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. 
The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
*/

// Set a struct of treenode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {};
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {};
};


class Solution {
private:
        // Using results to record the number of cameras
        int results;
    int traversal(TreeNode* curr) {
        // Step_01: Iterative method should set the ending point
        // Return 2 means the Null node is be covered
        if(curr == NULL) return 2;

        // Left
        int left = traversal(curr->left);
        // Right
        int right = traversal(curr->right);
        // Mid
        if(left == 2 && right == 2) return 0;
        if(left == 0 || right == 0) {
            results++;
            return 1;
        }
        if(left == 1 || right == 1) return 2;

        // this one is not necessary because we have already included all the situations.
        return -1;
    }


public:
    int minCameraCover(TreeNode* root) {
        // set the default results
        results = 0;
        // Situation 4:
        if(traversal(root) == 0) results++;

        return results;
    }
};
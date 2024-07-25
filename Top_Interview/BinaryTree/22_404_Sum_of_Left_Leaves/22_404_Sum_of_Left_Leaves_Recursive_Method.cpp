#include <iostream>
using namespace std;

/*
    [Question]
    Given the root of a binary tree, return the sum of all left leaves.

    A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 24
    Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

    Example 2:

    Input: root = [1]
    Output: 0

    [Thought]
        1. The problem can be solved by "Recursive Method" and "Iterative Method".
        2. Below the code, we use the "Recursive Method".


*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {};
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {};
};


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {


        // if root == null , return 0
        if(root == NULL) return 0;

        // Using Postorder
            // Left
        int leftNode = sumOfLeftLeaves(root->left);
        if(root->left && !root->left->left && !root->left->right) leftNode = root->left->val;
            // Right
        int rightNode = sumOfLeftLeaves(root->right);
            // Mid
        // Create a result for adding the left-node value
        int result = leftNode + rightNode;

        return result;
    }
};

int main() {
    
    /*
        Example 1:
        Input: root = [3,9,20,null,null,15,7]
    */

   TreeNode* root = new TreeNode(3);
   root->left = new TreeNode(9);
   root->right = new TreeNode(20);
   root->right->left = new TreeNode(15);
   root->right->right = new TreeNode(7);

   Solution solution;

   int result = solution.sumOfLeftLeaves(root);

    cout << result << " ";
    cout << endl;
    
    return 0;
}
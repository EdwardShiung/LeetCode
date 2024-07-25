#include <iostream>
using namespace std;


/*

    [Question]
    Given the root of a binary tree and an integer targetSum, 
    return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

    A leaf is a node with no children.
    
    Example 1:

        Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
        Output: true
        Explanation: The root-to-leaf path with the target sum is shown.
    
    Example 2:

        Input: root = [1,2,3], targetSum = 5
        Output: false
        Explanation: There two root-to-leaf paths in the tree:
        (1 --> 2): The sum is 3.
        (1 --> 3): The sum is 4.
        There is no root-to-leaf path with sum = 5.

    Example 3:

        Input: root = [], targetSum = 0
        Output: false
        Explanation: Since the tree is empty, there are no root-to-leaf paths.

    [Thought]
        1. The problem can be solved by "Recursive Method" and "Iterative Method".
        2. Below the code, we use the "Recursive Method (Preorder Method)" with "Backtracking".
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
    bool traversal(TreeNode* node, int total) {
        // 終止條件
        // 遇到葉子節點，並且達到了目標值 （用扣的方式來計算，因此達到 0 時，代表目標值達到）
        if(node->left == NULL && node->right == NULL && total == 0) return true;
        // 遇到葉子節點，但卻沒有找到合適的值返回
        if(node->left == NULL && node->right == NULL) return false;

        // 左
        if(node->left) {
            total -= node->left->val;
            if(traversal(node->left, total)) return true;
            total += node->left->val;
        }
        // 右
        if(node->right) {
            total -= node->right->val;
            if(traversal(node->right, total)) return true;
            total += node->right->val;
        }
        return false;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return traversal(root, targetSum - root->val);
    }
};

int main() {
    return 0;
}
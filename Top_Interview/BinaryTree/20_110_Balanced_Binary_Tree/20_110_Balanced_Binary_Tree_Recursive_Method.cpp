#include <iostream>
using namespace std;


/*
    [Question]
        Given a binary tree, determine if it is height-balanced.
    
    Example_01:
        Input: root = [3,9,20,null,null,15,7]
        Output: true
    
    Example_02:
        Input: root = [1,2,2,3,3,null,null,4,4]
        Output: false

    Example_03:
        Input: root = []
        Output: true

    [Thought]
    1. 本題可以用 "Recursive Method" 或 "Iterative Method"。但要記住，使用 Iterative Method 方法時，無法使用 Level Order Traversal。
        --> 相似題 LeetCode 104 中，可以使用 層序遍歷 求取深度，但無法使用 層序遍歷 求高度。

    2. 此程式碼為 "Iterative Method"

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

    int getHeight(TreeNode* node) {
        if(node == NULL) return 0;
        // 後序遍歷
            // 左
        int leftHeight = getHeight(node->left);
            // 如果返回值為 -1，代表高度差，超過 1
        if(leftHeight == -1) return -1;
            // 右
        int rightHeight = getHeight(node->right);
            // 如果返回值為 -1，代表高度差，超過 1
        if(rightHeight == -1) return -1;

            // 中
        int result;
        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        }else {
            result = 1 + max(leftHeight, rightHeight);
        }
        return result;
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    bool result = solution.isBalanced(root);
    cout << result << endl;

    return 0;
}
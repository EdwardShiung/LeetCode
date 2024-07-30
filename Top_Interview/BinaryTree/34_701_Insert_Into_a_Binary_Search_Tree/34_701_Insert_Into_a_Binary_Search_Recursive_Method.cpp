#include <iostream>
using namespace std;

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

    TreeNode* traversal(TreeNode* cur, int val) {
        // 終止條件：當前節點為空，創建新節點並返回
        if (cur == NULL) {
            return new TreeNode(val);
        } 
        // if cur->val > val, 往左
        if (cur->val > val) {
            cur->left = traversal(cur->left, val);
        } 
        // if cur->val < val, 往右
        else if (cur->val < val) {
            cur->right = traversal(cur->right, val);
        }
        return cur;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return traversal(root, val);
    }
};
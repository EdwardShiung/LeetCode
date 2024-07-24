#include <iostream>
using namespace std;


/*

    本題可以使用“ Recursive Method” 及 "Iterative Method_Level Order Traversal"

    此程式碼展示 Recursive Method，並且使用“後序”

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

    int getNodes(TreeNode* cur) {
        // 終止條件
        if(cur == NULL) return 0;
        // 後序
            // 左
        int leftNum = getNodes(cur->left);
            // 右
        int rightNum = getNodes(cur->right);
            // 中
        int total = leftNum + rightNum + 1;
        
        return total;
    }

    int countNodes(TreeNode* root) {
        return getNodes(root);
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution solution;
    int result = solution.countNodes(root);
    cout << result << endl;
    return 0;
}
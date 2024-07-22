#include <iostream>
using namespace std;

/*
    [Question]
    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    [Thought]
    1. Maximum Depth could use Recursive Method and Iterative Method.
        - Recursive Method
            - PreOrder Method
            - PostOrder Method
        - Iterative Method
            - Queue Method
            - Stack Method
    
    2. Using "Recursive (PostOrder) Method" to solve the problem.

        [Concept]
        - 需要了解 "高度" 和 "深度" 差異
            -   求"深度" 為根節點到最遠葉子節點的最長路徑上的節點數。    
                -- 前序遍歷 -中、左、右（由上往下）
            -   求"高度" 為二叉樹中，任一一個節點，到最遠葉子節點的距離。
                -- 後序遍歷 -左、右、中（由下往上）

        ps. 由於"根節點的（最大）高度" 為 根節點的最大深度，因此"後序法"和"前序法" 皆可以使用。

    [Similar LeetCode Problem]
    1. LeetCode 104
    2. LeetCode 559
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

    int getHeight(TreeNode* root) {
        // 設定終止挑件
        if(root == NULL) return 0;
        // get left-height
        int leftHeight = getHeight(root->left);
        // get right-height
        int rightHeight = getHeight(root->right);
        // mid node to deal with the height
        int height = 1 + max(leftHeight, rightHeight);
        return height;
    }

    int maxDepth(TreeNode* root) {
        return getHeight(root);
    }
};



int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.getHeight(root);

    cout << result << " ";
    cout<< endl;
    return 0;
}


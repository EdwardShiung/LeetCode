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
    
    2. Using "Recursive (PreOrder) Method" to solve the problem.

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

    // 這邊參數部分，給定 depth，是因為 leetcode 是將 root 視為第一層。所以可以看到，在 maxDepth 調用 getDepth 時，給定 depth == 1
    // 真實面試時，依情況而定。
    
    // 設定初始深度 
    int result = 0;

    void getDepth(TreeNode* node, int depth) {
        
        // 設定終止條件：當節點，沒有左子節點和右子節點時（同時沒有)，代表已達到終止條件。
        if(!node) return;

        // 中、左、右處理深度，因此中間節點為處理結果
            // 中
        result = max(result, depth);
            // 左
        if(node->left) getDepth(node->left, depth + 1);
            // 右
        if(node->right) getDepth(node->right, depth + 1);
    }

    int maxDepth(TreeNode* root) {

        if(root == NULL) return result;

        getDepth(root, 1);

        return result;
    }
};



int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.maxDepth(root);

    cout << result << " ";
    cout<< endl;
    return 0;
}

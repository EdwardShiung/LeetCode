#include <iostream>
#include <queue>
using namespace std;

/*

    [Question]
    
    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    Note: A leaf is a node with no children.

    [Thought]
    1. Minimum Depth could use Recursive Method and Iterative Method.

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

    The concept is the same with level order traversal by using queue to do that.

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
    int minDepth(TreeNode* root) {
        int resultDepth = 0;
        if(root == nullptr) return resultDepth;

        // Create a Queue
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            resultDepth++;

            // Record the numbers of nodes in the same level
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = queue.front();
                queue.pop();

                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
                if(!cur->left && !cur->right) return resultDepth;
            }
        }
        return resultDepth;
    }
};
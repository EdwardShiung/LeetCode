#include <iostream>
#include <queue>
using namespace std;

/*

    The concept is the same with level order traversal by using queue to do that.
    Just only one thing is different with LeetCode 104.
        - Once the child node of left and right are non at the same time, it need to return the depth, which means it's in the minimum depth.

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
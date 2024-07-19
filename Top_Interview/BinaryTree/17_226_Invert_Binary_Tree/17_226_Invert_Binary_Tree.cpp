#include <iostream>
#include <queue>
using namespace std;


/*
    The problem of invert binary tree is an easy problem.

    [Review]
    1. Understanding how to create "swap" function by hand made
        -   Understanding the type of pointer
            1. Reference to pointers
            2. Pointers
            3. Pointers to const
            4. Const pointers
            5. Const pointers to const
            6. Null pointers
            7. Dangling pointers
            8. Smart pointers

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
    TreeNode* invertTree(TreeNode* root) {
        // Create an queue to assist for level order traversal
        queue<TreeNode*> queue;
        // if root == null, return 
        if(root != nullptr) queue.push(root);
        // Using while-loop to do the level order traversal
        while(!queue.empty()) {
            // Recode each size of nodes in the same layer
            int size = queue.size();
            // Using for-loop to run node in the same layer
            for(int i = 0; i < size; i++) {
                TreeNode* cur = queue.front();
                queue.pop();
                // Key Point for swap here
                swap(cur->left, cur->right);
                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
            }
        }
        return root;
    }
};


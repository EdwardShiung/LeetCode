

/*
Given the root of a binary tree, 
return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/
#include <iostream>
#include <deque>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Edge Case
        if(!root) return {};

        // Using vector to store the result
        vector<vector<int>> res;
        // Using deque to assist to process the outcome
        deque<TreeNode*> dq;
        dq.push_back(root);

        // Set a flag to change the direction
        bool left_to_right = true;

        // Using a for-loop to process the result
        while(!dq.empty()) {
            // Using a temp vector to store 
            vector<int> level_node;
            // Record the number of node in each layer
            int level_size = dq.size();

            // for-loop 
            for(int i = 0; i < level_size; i++) {
                TreeNode* node;
                if (left_to_right) {
                    // left to right 代表從 下標 0 開始
                    node = dq.front();
                    dq.pop_front();
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                }else {
                    // right to left 代表從 下標 length開始 
                    node = dq.back();
                    dq.pop_back();
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                }
                level_node.push_back(node->val);
            }
            res.push_back(level_node);
            left_to_right = !left_to_right;
        }
        return res;
    }
};


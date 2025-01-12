/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:

Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // Using a result to store the value
        vector<int> res;
        // Edge Case
        if(!root) return res;
        // Using the deque to assist to process the outcome
        deque<TreeNode*> dq;
        // root node enter to the queue
        dq.push_back(root);

        // Using while loop to process the outcome
        while(!dq.empty()) {
            // Record the most right position of node in deque
            TreeNode* rightSide;
            // Record the number of node in each layer
            int numNode = dq.size();

            // Process each layer
            for(int i = 0; i < numNode; i++) {
                
                TreeNode* node = dq.front();
                dq.pop_front();

                if(node) {
                    rightSide = node;
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                }
            }
            if(rightSide) res.push_back(rightSide->val);
        }

        return res;
    }
};

int main() {

    /*
        Input: root = [1,2,3,null,5,null,4]
        Output: [1,3,4]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    for(int num : result) {
        cout << num << endl;
    }
}
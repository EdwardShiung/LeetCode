#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    The classic binary tree problem for "level order traversal" using "queue method".
    Here I categorize the type of level order traversal.
    1. LeetCode 102
    2. LeetCode 107
    3. LeetCode 199
    4. LeetCode 637
    *5. LeetCode 429 
    6. LeetCode 515
    7. LeetCode 116
    8. LeetCode 117
    9. LeetCode 104
    10.LeetCode 111 

    Above question could use "Level of Traversal Method" and "Recursive Method".

    [Review]
    1. Understanding how to use INT_MIN
*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // Create a results
        vector<int> results;
        // Because we need to do level of traversal, queue will be a good strategy to do that.
        queue<TreeNode*> queue;

        // if root == NULL, return results
        if(root == NULL) return results;

        // if root != NULL, put into the queue
        queue.push(root);

        // while-loop to do the level of traversal
        while(!queue.empty()) {
            // Each layer of size (Getting how many nodes in the same layer!)
            int size = queue.size();
            // for-loop for each layer
            // 取每一層的最大值
            int temp = INT_MIN; 
            for(int i = 0; i < size; i++) {
                // create a pointer to point a node
                TreeNode* cur = queue.front();
                // store the value to the temp (We need to find a bigger one, so setting the condition)
                temp = cur->val > temp ? cur->val : temp;
                // pop out the node from the queue
                queue.pop();
                // Keep going to push the children node to the queue
                // Left
                if(cur->left) queue.push(cur->left);
                // Right
                if(cur->right) queue.push(cur->right);
            }
            results.push_back(temp);
        }
        return results;
    }
};
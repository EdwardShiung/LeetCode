#include <iostream>
#include <queue>
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
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        // Create Results Vector
        vector<double> results;

        // Because we need to do level of traversal, queue will be a good strategy to do that.
        queue<TreeNode*> queue;

        // if(root == NULL) return results;
        if(root == NULL) return results;

        // if root != NULL, put the root into the queue
        queue.push(root);

        // while-loop to do the level of traversal
        while(!queue.empty()) {
            // Each layer of size (Getting how many nodes in the same layer!)
            int size = queue.size();

            // temp store the average
            double temp = 0;
            for(int i = 0; i < size; i++) {
                // Using pointer to point the node
                TreeNode* cur = queue.front();
                // Store the value of node
                temp += cur->val;
                // pop the node from the queue
                queue.pop(); 
                // Cur pointer to point the next one (Left -> Right)
                // Left
                if(cur->left) queue.push(cur->left);
                // Right
                if(cur->right) queue.push(cur->right);
            }
            temp = temp / size;
            results.push_back(temp);
        }
        return results;
    }
};


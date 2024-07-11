#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    The classic binary tree problem for "level order traversal" using "queue method".
    Here I categorize the type of level order traversal.
    1. LeetCode 102
    2. LeetCode 107
    3. LeetCode 199
    4. LeetCode 637
    5. LeetCode 429
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Store the results (All of Layers of Nodes)
        vector<vector<int>> results;
        // Create Queue
        queue<TreeNode*> queue;
        // if root == NULL return results
        if(root == NULL) return results;

        // put the root into queue
        queue.push(root);

        // while-loop to 
        while(!queue.empty()) {
            // Each layer has size of node
            int size = queue.size();
            // Store each layer to the vector
            vector<int> vec;

            // for-loop each layer
            for(int i = 0; i < size; i++) {
                TreeNode* cur = queue.front();
                // Pointer to the node
                // Save the node value in results
                vec.push_back(cur->val);
                // pop the node 
                queue.pop();
                // Put the node to the queue (from left to right)
                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
            }
            results.push_back(vec);
        }
        return results;
    }
};

int main() {

    Solution solution;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> results = solution.levelOrder(root);

    for(int i = 0; i < results.size(); i++) {
        cout << "[";
        for(int j = 0; j < results[i].size(); j++) {
            cout << "[" << results[i][j] << "]";
        } 
        cout << "]";
    }

    cout << endl;
    return 0;
}
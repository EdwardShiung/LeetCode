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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> que;

        if (root != NULL) que.push(root);

        vector<int> result;

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == (size - 1)) result.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};


int main() {
    return 0;
}
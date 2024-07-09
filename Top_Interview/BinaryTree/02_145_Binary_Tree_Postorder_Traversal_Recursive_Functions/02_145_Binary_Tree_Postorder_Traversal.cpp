#include <iostream>
#include <vector>
using namespace std;


/*

    The classic binary tree problem.
    Here I categorize the type of binary tree problem.
    1. Preorder Traversal --> LeetCode 144
    2. Inorder Traversal  --> LeetCode 94
    3. PostOrder Traversal --> LeetCode 145  

    [Review] 
    1. Review the 3 requirements in recursive method.
        - 確定 Recursive Function 參數 和 返回值
        - 終止條件
        - 確定單層邏輯
*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


class Solution {
public:

    void traversal(TreeNode* cur, vector<int>& vec) {
        if(cur == NULL) return;
        // Left
        traversal(cur->left, vec);
        // right
        traversal(cur->right, vec);
        // middle
        vec.push_back(cur->val);

    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        traversal(root, results);
        return results;
    }
};


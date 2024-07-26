#include <iostream>
#include <queue>
using namespace std;

/*
    [Question]
    You are given two binary trees root1 and root2.

    Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. 
    You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
    Otherwise, the NOT null node will be used as the node of the new tree.

    Return the merged tree.

    Note: The merging process must start from the root nodes of both trees.

    Example 1:

        Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
        Output: [3,4,5,5,4,null,7]  
    
    Example 2:

        Input: root1 = [1], root2 = [1,2]
        Output: [2,2]

    [Though]
    1. The problem can be solved by "Recursive Method" & "Iterative Method".

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 終止條件
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        if(root1 == NULL && root2 == NULL) return NULL;

        // 使用”前序“
        // M
        TreeNode* root = new TreeNode(root1->val + root2->val);
        // L
        root->left = mergeTrees(root1->left, root2->left);
        // R
        root->right = mergeTrees(root1->right, root2->right);

        return root;
    }
    void printResult(TreeNode* root) {
        if(!root) {
            cout << "null" << endl;
            return;            
        }
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            TreeNode* cur = queue.front();
            queue.pop();

            if(cur) {
                cout << cur->val << " ";
                queue.push(cur->left);
                queue.push(cur->right);
            }else{
                cout << "null";
            }
        }
    }
};

int main() {
    Solution solution;

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    TreeNode* results = solution.mergeTrees(root1, root2);

    solution.printResult(results);


    return 0;
}

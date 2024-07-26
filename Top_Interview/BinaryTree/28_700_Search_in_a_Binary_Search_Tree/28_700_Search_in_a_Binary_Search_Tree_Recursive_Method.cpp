#include <iostream>
#include <queue>
using namespace std;


/*
    [Question]
    You are given the root of a binary search tree (BST) and an integer val.

    Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
    If such a node does not exist, return null.

    Example 1:
    
        Input: root = [4,2,7,1,3], val = 2
        Output: [2,1,3]

    Example 2:
        
        Input: root = [4,2,7,1,3], val = 5
        Output: []

    [Thought]
        1. The question can be solved by "Recursive Method" & "Iterative Method".
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

    TreeNode* searchBST(TreeNode* root, int val) {
       // 終止條件
       if(root == NULL || root->val == val) return root;
       
       // root != NULL，繼續尋找
       // 找到的話，存入 result
       TreeNode* results;
       // Left
       if(root->val > val) return results = searchBST(root->left, val);
       // Right
       if(root->val < val) return results = searchBST(root->right,val);

        return NULL;
    }

    void printResult(TreeNode* root) {
        if(!root) {
            cout << "null";
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
            }else {
                cout << "null";
            }
        }
    }
};


int main() {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;

    Solution solution;

    TreeNode* results = solution.searchBST(root, val);

    solution.printResult(results);

    return 0;
}
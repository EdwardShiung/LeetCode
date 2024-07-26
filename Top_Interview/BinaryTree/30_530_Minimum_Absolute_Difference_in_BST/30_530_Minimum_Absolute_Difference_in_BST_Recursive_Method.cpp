#include <iostream>
using namespace std;

/*
    [Question]
    Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

    Example 1:
        
        Input: root = [4,2,6,1,3]
        Output: 1

    Example 2:
        Input: root = [1,0,48,null,null,12,49]
        Output: 1

    [Thought]
        1. The question can be solved by "Recursive Method" & "Iterative Method".
        2. Change you mind to think about finding a minimum vale from order array (from small number to large number).
            --> 重要觀念！！二差搜索樹可以看成有序陣列！
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
    // Using an array to store the value of node
    vector<int> vec;
    void traversal(TreeNode* node) {
        if(node == NULL) return;
        traversal(node->left);
        vec.push_back(node->val);
        traversal(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        int result = INT_MAX;
        for(int i = 1; i < vec.size(); i++) {
            result = min(result, vec[i] - vec[i - 1]);
        }
        return result;
    }
};

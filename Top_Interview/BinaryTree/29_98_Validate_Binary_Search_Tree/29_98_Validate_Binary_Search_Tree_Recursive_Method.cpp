#include <iostream>
using namespace std;

/*

    [Question]

    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

    Example 1:
        
        Input: root = [2,1,3]
        Output: true

    Example 2:
        
        Input: root = [5,1,4,null,null,3,6]
        Output: false
        Explanation: The root node's value is 5 but its right child's value is 4.

    [Thought]:
            1. The question can be solved by "Recursive Method" & "Iterative Method".
            2. Recursive Method could use "in-order method".
                --> L M R
                --> After using in-order method to store value of node, it could have a order number in the array.
                    --> which means that it will order from small number to large number.
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
private:
    vector<int> vec;
    void traversal(TreeNode* node) {
        if(node == NULL) return;
        traversal(node->left);
        vec.push_back(node->val);
        traversal(node->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        traversal(root);
        for(int i = 1; i < vec.size(); i++) {
            if(vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
};


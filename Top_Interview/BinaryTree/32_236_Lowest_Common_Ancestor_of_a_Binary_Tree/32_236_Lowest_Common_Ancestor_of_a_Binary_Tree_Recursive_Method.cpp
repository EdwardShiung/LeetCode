#include <iostream>
using namespace std;

/*
    [Question]
    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

    According to the definition of LCA on Wikipedia: 
    “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
    (where we allow a node to be a descendant of itself).”

    Example 1:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        Output: 3
        Explanation: The LCA of nodes 5 and 1 is 3.

    Example 2:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
        Output: 5
        Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

    Constraints:

        The number of nodes in the tree is in the range [2, 105].
        -109 <= Node.val <= 109
        All Node.val are unique.
        p != q
        p and q will exist in the tree.

    [Thought]
        1. 首先想到利用深度方式來找尋父節點
        2. “深度”方法，所以 使用 "後序" + ”回朔“ 方法，可以找到 common ancestor
            -   後序：可以根據左、右兩個節點情況，在中間節點做處理
                - 後序，可以說是天然的回朔法 
    
    [Similar Question]
        1. LeetCode 236 Binary Tree
        2. LeetCode 235 Binary Search Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 終止條件：
            // 終止條件有兩種情況：
            // 1. root == NULL, return NULL
            // 2. root == p 節點 或者 root == q 節點, 這兩種情況下，直接返回
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;

        // 單層邏輯 （遞歸法-後序）
        // L
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // R
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // M (中間處理)
        if (left != NULL && right != NULL) return root;
        if(left == NULL && right != NULL) return right;
        if(left != NULL && right == NULL) return left;
        // left == NULL && right == NULL
        else return NULL;
    }
};




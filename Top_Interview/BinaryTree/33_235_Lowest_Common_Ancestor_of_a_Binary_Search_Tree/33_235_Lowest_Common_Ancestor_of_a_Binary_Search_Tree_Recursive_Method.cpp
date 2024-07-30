#include <iostream>
using namespace std;


/*
    [Question]
    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: 
    
    “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
    (where we allow a node to be a descendant of itself).”

    Example 1:
        Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
        Output: 6
        Explanation: The LCA of nodes 2 and 8 is 6.
    
    Example 2:
        Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
        Output: 2
        Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
    
    Example 3:

        Input: root = [2,1], p = 2, q = 1
        Output: 2

    [Thought]
        1. 本題與 236 最大不同點：
            - Binary Search Tree 有序性！
        2. 透過 BST 自帶的特性，可以得知
            - BST 左邊 node < 中間 node
            - BST 右邊 node > 中間 node   
            - 最小公共節點，必定在區間 [p, q] 之間

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
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        // cur 
        if(cur == NULL) return NULL;

        // cur->val > p->val && cur->val > q->val, 請往左邊走
        if(cur->val > p->val && cur->val > q->val) {
            TreeNode* left = traversal(cur->left, p, q);
            if(left != NULL) return left;
        }

        // cur->val < p->val && cur->val < q->val, 請往右邊走
        if(cur->val < p->val && cur->val < q->val) {
            TreeNode* right = traversal(cur->right, p, q);
            if(right != NULL) return right;
        }
        return cur;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};
#include <iostream>
using namespace std;

/*
    [Question]
    You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
    Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
    Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

    Example 1:

        Input: root = [4,2,7,1,3], val = 5
        Output: [4,2,7,1,3,5]
        Explanation: Another accepted tree is:

    Example 2:

        Input: root = [40,20,60,10,30,50,70], val = 25
        Output: [40,20,60,10,30,50,70,null,null,25]

    Example 3:

        Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
        Output: [4,2,7,1,3,5]
    

    Constraints:

        The number of nodes in the tree will be in the range [0, 104].
        -108 <= Node.val <= 108
        All the values Node.val are unique.
        -108 <= val <= 108
        It's guaranteed that val does not exist in the original BST.

    [Thought]
    1. The problem can be solved by "Recursive Method" and "Iterative Method".

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

    TreeNode* traversal(TreeNode* cur, int val) {
        // 終止條件：當前節點為空，創建新節點並返回
        if (cur == NULL) {
            return new TreeNode(val);
        } 
        // if cur->val > val, 往左
        if (cur->val > val) {
            cur->left = traversal(cur->left, val);
        } 
        // if cur->val < val, 往右
        else if (cur->val < val) {
            cur->right = traversal(cur->right, val);
        }
        return cur;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return traversal(root, val);
    }
};
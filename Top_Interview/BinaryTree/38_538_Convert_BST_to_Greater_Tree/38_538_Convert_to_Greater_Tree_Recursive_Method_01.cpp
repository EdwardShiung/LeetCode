#include <iostream>
using namespace std;

/*

    [Question]
    Given the root of a Binary Search Tree (BST), 
    convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

    As a reminder, a binary search tree is a tree that satisfies these constraints:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    

    Example 1:
        
        Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
        Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

    Example 2:
        
        Input: root = [0,null,1]
        Output: [1,null,1]

    Constraints:

        The number of nodes in the tree is in the range [0, 104].
        -104 <= Node.val <= 104
        All the values in the tree are unique.
        root is guaranteed to be a valid binary search tree.

    [Thought]
    1. 本題會發現，有序的 BST 可以思考為 有序的陣列。
        - 原因：本題如果為陣列思考，會發現此陣列，由後面累加至前面
            - 因此可以得出 遞歸順序：右、中、左
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
    int preValue = 0;
    
    void traversal(TreeNode* cur) {
        if(cur == NULL) return;
        // R
        traversal(cur->right);
        // M
        cur->val += preValue;
        preValue = cur->val;
        // L
        traversal(cur->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};  



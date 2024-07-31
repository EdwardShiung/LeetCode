#include <iostream>
using namespace std;

/*
    [Question]
    Given the root of a binary search tree and the lowest and highest boundaries as low and high, 
    trim the tree so that all its elements lies in [low, high]. 
    Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., 
    any node's descendant should remain a descendant). 
    It can be proven that there is a unique answer.

    Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

    

    Example 1:

        Input: root = [1,0,2], low = 1, high = 2
        Output: [1,null,2]

    Example 2:

        Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
        Output: [3,2,null,1]
    
    [Thought]
    1. 利用 BST 特性，可以做出來這道題目！
    2. 本題請多思考！！

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
    TreeNode* trimBST(TreeNode* root, int low, int hight) {
        // 終止條件
        if(root == nullptr) return nullptr;
        
        // if root-> val < low, 應該要遞歸右子樹，並且最終返回右子樹 (代表左邊已經小於 範圍內)
        if(root->val < low) {
            TreeNode* right = trimBST (root->right, low, hight);
            return right;
        }
        // if root-> val > hight, 應該要遞歸左子樹，並且最終返回左子樹 (代表右邊已經超於 範圍內)
        if(root->val > hight) {
            TreeNode* left = trimBST(root->left, low, hight);
            return left;
        }

        // root->left 接入符合條件的 左子樹
        root->left = trimBST(root->left, low, hight);
        // root->right 接入符合條件的 右子樹
        root->right = trimBST(root->right, low, hight);

        return root;
    }
};
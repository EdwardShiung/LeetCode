#include <iostream>
using namespace std;

/*
    [Question]
    Given an integer array nums where the elements are sorted in ascending order, convert it to a 
    height-balanced binary search tree.

    Example 1:
        
        Input: nums = [-10,-3,0,5,9]
        Output: [0,-3,9,-10,null,5]
        Explanation: [0,-10,5,null,-3,null,9] is also accepted:

    Example 2:

        Input: nums = [1,3]
        Output: [3,1]
        Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

    [Thought]
    1. 題目強調 height-balanced binary search tree，原因是，如果不限制，將有很多種答案的 二叉搜索樹。
    2. 平衡二叉樹定義：左右兩子樹，高度不能超過 1。
    3. 想法很簡單，因為給定的有序陣列，中間下標必定為 root。
        -   可以說，有序陣列，必定可以為 BST

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

    TreeNode* traversal(vector<int>& nums, int left, int right) {
        // 當陣列中，左邊的值，大餘右邊的值，則代表結束遞歸
        if(left > right) return nullptr;
        // 計算中間值 （作為 root）
        int mid = left + ((right - left) / 2);
        // 將 mid 作為 root
        TreeNode* root = new TreeNode(nums[mid]);
        // L
        root->left = traversal(nums, left, mid - 1);
        // R
        root->right = traversal(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};
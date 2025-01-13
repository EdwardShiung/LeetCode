/*
Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 
Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., 
we can do insert and delete operations) and you need to find the kth smallest frequently, 
how would you optimize?

[Thought]:
1. 本題"DFS"且用 Recursive Method 的 Inorder Method
*/
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // Using a res variable to store the inorder process
        vector<int> res;
        // Using a helper function to process the inorder traversal
        helper(root, res);
        return res[k - 1];
    }
private:
    void helper(TreeNode* node, vector<int>& res) {
        // Base Case
        if(!node) return;
        helper(node->left, res);
        res.push_back(node->val);
        helper(node->right, res);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    Solution sol;
    int result = sol.kthSmallest(root, 1);
    cout << result << endl;
}
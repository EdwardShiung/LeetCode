/* 
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes 
in the sequence has an edge connecting them. A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

[Reference Link]:
https://www.youtube.com/watch?v=nLYHbrMpBRs

[TC]: O(n)
[SC]: O(n)

*/

#include <iostream>
// Include the climits header for INT_MIN
#include <climits>
using namespace std;

class TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int res;
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        helper(root);
        return res;
    }
private:
    int helper(TreeNode* root) {
        if(!root) return 0;
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};

int main() {
    Solution sol;
    
}
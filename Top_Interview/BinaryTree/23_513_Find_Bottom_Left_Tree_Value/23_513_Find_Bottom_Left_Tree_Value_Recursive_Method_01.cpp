#include <iostream>
using namespace std;

/*
    [Question]
    Given the root of a binary tree, return the leftmost value in the last row of the tree.

    Example_01:
    Input: root = [2,1,3]
    Output: 1

    Example_02:
    Input: root = [1,2,3,4,null,5,6,null,null,7]
    Output: 7

    [Thought]
        1. The problem can be solved by "Recursive Method" and "Iterative Method".

        2. 本題，關鍵：“找尋深度”！！
                --> 最簡單的做法 Iterative Method (level Order Traversal)

        3. 如果使用 Recursive Method，因為需要不停地回到 root 尋找，Backtracking 重要！！

        4. LeetCode 513 要求的是返回二元樹最後一行的最左邊的值，而不僅僅是左邊的子節點。這意味著如果最後一行只有右子節點，也可以算。

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
    // 使用 全局變量，儲存 maxDepth (使用 C++ 預先給定最小值)
    int maxDepth = INT_MIN;
    // 使用 全局變量，儲存 result
    int result;

    // （解題概念） 因為求深度，所以使用 ”前序“。但因為 中間不處理任何狀況，所以沒有中間問題
    void traversal(TreeNode* node, int depth) {
        //終止條件
            // 更新 maxDepth
            // 更新 result 的值
        if(node->left == NULL && node->right == NULL) {
            if(depth > maxDepth) {
                // 更新 maxDepth
                maxDepth = depth;
                // 更新 result 
                result = node->val;
            }
        }

        // 中：不用處理

        // 左：因為用 Recursive Method，所以要記得回到 root 的情況下，使用 Backtracking
        if(node->left) {
            depth++;
            traversal(node->left, depth);
            depth--;
        }

        // 右：因為用 Recursive Method，所以要記得回到 root 的情況下，使用 Backtracking
        if(node->right) {
            depth++;
            traversal(node->right, depth);
            depth--;
        }
    
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    Solution solution;

    int result = solution.findBottomLeftValue(root);

    cout << result << " ";
    cout << endl;

    return 0;
}
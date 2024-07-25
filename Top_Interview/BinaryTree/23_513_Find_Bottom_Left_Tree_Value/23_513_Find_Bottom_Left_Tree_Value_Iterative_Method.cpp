#include <iostream>
#include <queue>
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

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {};
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {};
};



class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // if root == NULL, return 0
        if(root == NULL) return 0;
        // Using queue to assist the level order traversal
        queue<TreeNode*> queue;
        // Using result to record the last node 
        int result = 0;

        // if root != NULL, put it to the queue
        queue.push(root);

        // Using while-loop to do level order traversal 
        while(!queue.empty()) {
            // Record the size of nodes at the same layer
            int size = queue.size();

            // Using the for-loop to traverse each node in the same layer
            for(int i = 0; i < size; i++) {

            // Using the pointer to point the node
            TreeNode* cur = queue.front();
            queue.pop();

            // Every time, once the first node at the same layer, it will store to the result
            if(i == 0) result = cur->val;

            if(cur->left) queue.push(cur->left);
            if(cur->right) queue.push(cur->right);

            }

        }
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
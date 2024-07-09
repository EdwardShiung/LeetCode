#include <iostream>
#include <stack>
using namespace std;

/*
    The classic binary tree problem.
    Here I categorize the type of binary tree problem.
    1. Preorder Traversal --> LeetCode 144
    2. Inorder Traversal  --> LeetCode 94
    3. PostOrder Traversal --> LeetCode 145  

    [Iterative Method]
        Binary Tree also can use iterative method.
        The process is just like using a stack structure.
    [Key Point]
        Inorder Traversal : Left -> Middle -> Right
        --> The logic is that the far left node of the tree should be put in the stack first.

*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Create a results
        vector<int> results;
        // Create a stack
        stack<TreeNode*> stack;
        // Using a pointer to point the current position of tree node.
        TreeNode* cur = root;

        while(cur != NULL || !stack.empty()) {
            // let the pointer to the far left node
            if(cur != NULL) {
                stack.push(cur);
                cur = cur->left;
            }else{
            // if is the end of the node, which means no child node
                cur = stack.top();
                stack.pop();
                // Middle
                results.push_back(cur->val);
                // Left
                cur = cur->right;
            }
        }
        
        return results;
    }
};

int main() {
    // import class Soluion
    Solution solution;
    // results variable
    vector<int> results;
    // Create TreeNode
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    results = solution.inorderTraversal(root);

    for(int i : results) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
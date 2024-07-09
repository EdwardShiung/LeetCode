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
        Preorder Traversal : Middle -> Left -> Right
        --> Using stack structure, so we need to change the sequence, especially left and right.
        --> so, the correct sequence is: Middle -> Right -> Left
*/




struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
         // Create a Results 
         vector<int> results;
         //Using stack structure
         stack<TreeNode*> stack;

         // put the root to the stack (if root == null return)
         if(root == NULL) return results;

         stack.push(root);
         // Using Stack to make the preorder traversal
         // if the stack don't have any Node, it will stop the while-loop.
         while(!stack.empty()) {
            // using a pointer to point the top value in the stack
            TreeNode* node = stack.top();
            // pop out the top value
            stack.pop();
            // Put the value to the result
            results.push_back(node->val);

            // Again, put the node chile to the stack
            // Before putting the child to the stack, we need to make sure there is a value in the left or right child.
            // Put the "Right" first, and then put "left"
                // Right
            if(node->right) stack.push(node->right);
                // Left
            if(node->left) stack.push(node->left);

         }
        return results;
    }
};



int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> results = solution.preorderTraversal(root);

    for(int i : results) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
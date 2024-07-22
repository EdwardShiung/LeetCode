#include <iostream>
#include <queue>
using namespace std;

/*

    [Question]
    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    [Thought]
    1. Maximum Depth could use Recursive Method and Iterative Method.
        - Recursive Method
            - PreOrder Method
            - PostOrder Method
        - Iterative Method
            - Queue Method
            - Stack Method
    
    2. Using "Iterative (Queue) Method" to solve the problem

        -   The concept is the same with level order traversal by using queue to do that.
        -   Using "Queue level order traversal Template" could solve the problem
    
    [Similar LeetCode Problem]
    1. LeetCode 104
    2. LeetCode 559
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {};
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {};
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Create a resultDepth 
        int resultDepth = 0;
        // Create a queue for assist the level order traversal
        queue<TreeNode*> queue;

        // if root == null, return resultDepth = 0
        if(root == nullptr) return resultDepth;
        // if root !- null, put the root into the queue
        queue.push(root);

        // while-loop for level order traversal
        while(!queue.empty()) {

            // Count the depth height
            resultDepth++;

            // Count the size of node in the same level
            int size = queue.size();
            for(int i = 0; i < size; i++) {

                // Using the pointer to point the node in the queue
                TreeNode* cur = queue.front();
                // pop the front node from queue
                queue.pop();

                // try to put the child node into the queue
                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
            
            }
        }
        cout << "Get the Depth of TreeNode: " << resultDepth << " ";
        cout << endl;
        return resultDepth;
    }
};

int main() {

    Solution solution;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    solution.maxDepth(root);


    return 0;
}
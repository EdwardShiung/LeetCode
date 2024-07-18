#include <iostream>
#include <queue>
using namespace std;

/*

    The concept is the same with level order traversal by using queue to do that

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
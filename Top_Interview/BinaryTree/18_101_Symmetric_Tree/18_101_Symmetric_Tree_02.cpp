#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

    [Thought]

    1. Iterative Method_Queue Method
        --> 可以思考成樹根，帶有兩個節點（一左、一右）
        --> 每次比較左右兩邊是否相等即可！
            --> 放的順序和比較的順序相同

    2. 請注意：這個不是層序遍歷

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
    bool isSymmetric(TreeNode* root) {
        // Create a Queue to assist to do Iterative Method
        queue<TreeNode*> queue;
        // if root == NULL, return true;
        if(root == NULL) return true;
        // if root != NULL, put the root.left && root.right into queue
        queue.push(root->left);
        queue.push(root->right);

        // Using while-loop to verify the left node and right node are symmetric
        while(!queue.empty()) {
            // In order to understand the symmetric, using the pointer to point the both side
                // Using the Left-Pointer to point the left node
                // Using the Right-Pointer to point the right node
            TreeNode* leftPointer = queue.front();
            queue.pop();
            TreeNode* rightPointer = queue.front();
            queue.pop();

            // Compared here!
                // if leftpointer == NULL && rightpointer == NULL, it could keep going to compare.
            if(!leftPointer && !rightPointer) continue;

                // if left or right not null or value of nodes are different, it should return false;
            if(!leftPointer || !rightPointer || (leftPointer->val != rightPointer->val)) return false;

            // Push the node into the queue
            queue.push(leftPointer->left);
            queue.push(rightPointer->right);
            queue.push(leftPointer->right);
            queue.push(rightPointer->left);
        }
        return true;
    }

    void traversal(TreeNode* cur, std::vector<int>& vec) {
        if(cur == NULL) return;
        // Left
        traversal(cur->left, vec);
        // right
        traversal(cur->right, vec);
        // value
        vec.push_back(cur->val);
    }


    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> results;
        traversal(root, results);
        return results;
    }
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    vector<int> results = solution.postorderTraversal(root);

    for(int i : results) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
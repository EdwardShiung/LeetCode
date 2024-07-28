#include <iostream>
#include <unordered_map>
using namespace std;


/*
    [Question]

    Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

    If the tree has more than one mode, return them in any order.

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
    Both the left and right subtrees must also be binary search trees.

    Example 1:

    Input: root = [1,null,2,2]
    Output: [2]

    Example 2:

    Input: root = [0]
    Output: [0]

    ps mode --> 眾數

    [Thought]
    1. 二叉搜索樹一定是中序遍歷

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
    //  利用 unordered_map 來儲存 
    // map 中的 key:    儲存 node value
    // map 中的 value:  儲存出現次數
    unordered_map<int, int> countMap;

    void traversal(TreeNode* node) {
        if(node == NULL) return;
        // L
        traversal(node->left);
        // M
        countMap[node->val]++;
        // R
        traversal(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        
        vector<int> result;
        
        if(root == NULL) return result;
        
        traversal(root);

        // 使用 for-loop 遍歷所有的 map value，找尋次數最多的！


        return result;
    }
};

int main() {
    
    // TreeNode* root = new TreeNode(0);
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution solution;

    vector<int> result = solution.findMode(root);



    return 0;
}





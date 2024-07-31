#include <iostream>
using namespace std;

/*
    [Question]

    Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
    Return the root node reference (possibly updated) of the BST.

    Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.
 

    Example 1:
        
        Input: root = [5,3,6,2,4,null,7], key = 3
        Output: [5,4,6,2,null,null,7]
        Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
        One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
        Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

    Example 2:

        Input: root = [5,3,6,2,4,null,7], key = 0
        Output: [5,3,6,2,4,null,7]
        Explanation: The tree does not contain a node with value = 0.

    Example 3:

        Input: root = [], key = 0
        Output: []

    [Thought]
    
    1.  做法可以分： 
        -   Recursive Method(不使用 BST 特性) -->     檔案 01 (較為直觀！！推薦！！)
        -   Recursive Method                -->     檔案 02 (較不直觀、難思考)
        -   Iterative Method                -->     檔案 03

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

    TreeNode* deleteNode(TreeNode* root, int key) {
        // (終止條件)：
            // 情況一：當到了葉子節點，還是沒有找到對應的值
        if(root == NULL) return NULL;
        
        // 找到了對應的值
        if(root->val == key) {
            
            // 情況二：在葉子節點中，找到相同的值
            if(root->left == nullptr && root->right == nullptr) {
                // 直接釋放這個節點
                delete root;
                return nullptr;
            }

            // 情況三：刪除節點左節點為空，右節點不為空
            if(root->left == nullptr && root->right != nullptr) {
                // 保存右節點部分
                TreeNode* restRightNode = root->right;
                // 刪除對應節點
                delete root;
                // 返回保留右子樹
                return restRightNode;
            }

            // 情況四：刪除節點左節點不為空，右節點為空
            if(root->left != nullptr && root->right == nullptr) {
                // 保存對應節點
                TreeNode* restLeftNode = root->left;
                // 刪除對應節點
                delete root;
                // 返回保留左子樹
                return restLeftNode;
            }

            // 情況五：刪除節點，左右皆不為空
            if(root->left != nullptr && root->right != nullptr) {
                // 刪除前，先將左子樹剩餘的部分，加到右子樹最左邊
                    // 利用 cur pointer 移動
                TreeNode* cur = root->right;
                while(cur->left != NULL) {
                    cur = cur->left;
                }
                    // 將左子樹，加到右子樹最左邊
                cur->left = root->left;
                // 刪除前，先保留
                TreeNode* tmp = root;
                // 保留右子樹為先
                root = root->right;
                // 刪除對應節點
                delete tmp;
                // [注意]：這裡返回就是返回全部 root（因為非葉子節點）
                return root;
            }
        }
        // 利用 BST 特性，進行遞歸
        // L 
        if(root->val > key) root->left = deleteNode(root->left, key);
        // R
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    };
};  
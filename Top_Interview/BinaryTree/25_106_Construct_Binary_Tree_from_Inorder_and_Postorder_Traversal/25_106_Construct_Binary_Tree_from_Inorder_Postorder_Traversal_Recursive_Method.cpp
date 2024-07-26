#include <iostream>
#include <vector>
using namespace std;

/*
    [Question]
    Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, 
    construct and return the binary tree.

    Example 1:

        Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
        Output: [3,9,20,null,null,15,7]

    Example 2:

        Input: inorder = [-1], postorder = [-1]
        Output: [-1]

    [Thought]
        Step_01: 如果後序 Array 為 0，返回空節點 (此為 Recursive Method 的終止條件)
        Step_02: 如果不為空，後序 Array 中，最後一個元素為節點（根節點）
        Step_03: 利用 step_02 找到的元素，作為中序 Array 的切割點
        Step_04: 切割“中序 Array” ，切成中序左陣列、中序右陣列 (一定先切割中序 Array)
        Step_05: 切割“後序 Array”，切成後序左陣列、後序右陣列
        Step_06: 使用遞歸處理左區間、右區間

    --> 反思：下面的程式碼運行並不好，每層遞歸都要定義新的 vector，不但耗時，也耗費空間。
            --> 但非常好理解！
            --> 優化方式就是利用下標分割，不使用新的陣列，請看02版本。

    [Similar Question]
    1. LeetCode 106
    2. LeetCode 105 
    3. LeetCode 654
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

    TreeNode *traversal(vector<int>& inorder, vector<int>& postorder) {

        // Step_01: 如果後序 Array 為 0，返回空節點 (此為 Recursive Method 的終止條件)
        if(postorder.size() == 0) return NULL;
        // Step_02: 如果不為空，後序 Array 中，最後一個元素為節點（根節點）
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        // 如果 “中序” 只有一個節點，直接返回 root
        if(inorder.size() == 1) return root;

        // Inorder 拆分
        // 如果 “中序” 不只有一個切割點，繼續做下面的切割：

            // Step_03: 利用 step_02 找到的元素，作為中序 Array 的切割點

                // Step_04: 切割“中序 Array” ，切成中序左陣列、中序右陣列 (一定先切割中序 Array)
                // 創建 indexInorder找 尋切割點
        int indexInorder;
        for(indexInorder = 0; indexInorder < inorder.size(); indexInorder++) {
            if(inorder[indexInorder] == root->val) break;
        }

        // 將 中序 Array 分成左右兩邊
            // 左中序
        vector<int> leftInorder(inorder.begin(), inorder.begin() + indexInorder);
            // 右中序
        vector<int> rightInorder(inorder.begin() + indexInorder + 1, inorder.end());


        // PostOrder 拆分 
                // 拆分之前，先 resize postorder
                    // postorder 捨棄最後一個元素，所以可以直接 resize
        postorder.resize(postorder.size() - 1);
                // Step_05: 切割“後序 Array”，切成後序左陣列、後序右陣列
                // 利用中序左陣列作為定位

                // 將 後序 Array 分成左右兩邊
                    // 左後序 
                    // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

                // 單層循環
                // Step_06: 使用遞歸處理左區間、右區間
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};

int main() {
    
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution solution;
    solution.buildTree(inorder, postorder);



    return 0;
}
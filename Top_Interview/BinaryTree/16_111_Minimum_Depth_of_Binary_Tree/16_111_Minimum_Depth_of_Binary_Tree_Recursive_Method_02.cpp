#include <iostream>
using namespace std;


/*

    [Question]
    
    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    Note: A leaf is a node with no children.

    [Thought]
    1. Minimum Depth could use Recursive Method and Iterative Method.

        - Recursive Method
            - PreOrder Method
            - PostOrder Method

        - Iterative Method
            - Queue Method
            - Stack Method
    
    2. Using "Recursive (PostOrder) Method" to solve the problem.

        [Concept]
        - 需要了解 "高度" 和 "深度" 差異
            -   求"深度" 為根節點到最遠葉子節點的最長路徑上的節點數。    
                -- 前序遍歷 -中、左、右（由上往下）
            -   求"高度" 為二叉樹中，任一一個節點，到最遠葉子節點的距離。
                -- 後序遍歷 -左、右、中（由下往上）

    3. The leetcode provide the test cases, which indicate that the shortest path from the root node down to the nearest leaf node.
    So, according to the problem, we understand the example
        
        Example_01:

        Input: root = [3,9,20,null,null,15,7]
        Output: 2

        --> The root could be the first level. (代表，root 被視為深度第一層)
        --> 題目最小深度的意思，為根節點，到葉子節點，最短距離。
            --> 題目可以求最小 "高度"（由 root 往 最近葉子節點數）--> 後序遍歷 --> 左右中 (將子節點情況，返回給父節點)
            --> 題目可以求最短 "深度" (由 葉子節點 往 root 節點) --> 前序遍歷 --> 中左右
                    --> 網路上大多為"後序"

        Example_02:

        Input: root = [1, null, 2, 4, 3, null, null, 6, 5]

        --> 注意：題目已經規定，最小深度的定義：shortest1 path from the root node down to the nearest leaf node.
            --> 此範例會發現，root左子節點為空，如果這樣計算的話，最小深度為 1。但最小深度定義在本題，必須是 root 到子節點的最短距離。

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
    int getHeight(TreeNode* node) {
        // 終止條件 (因為高度是由葉子節點開始計算，所以當葉子節點時，他的子節點為 NULL，高度為 0)
        if(!node) return 0; 

        // 本題用 "PostOrder"
            // Left-Node --> 取得左子樹，最小高度
        int leftDepth = getHeight(node->left);
            // Right-Node --> 取得右子樹，最小高度
        int rightDepth = getHeight(node->right);
            // Mid-Node (處理邏輯)--> 中間用來檢查哪一邊有子節點，且為葉子節點
                // 中間處理的情況下面三種
                    // 左為空
        if(node->left == NULL && node->right != NULL) return 1 + rightDepth;
                    // 右為空
        if(node->right == NULL && node->left != NULL) return 1 + leftDepth;
                    // 左、右兩子節點皆不為空，取最小值
        int result = 1 + min(leftDepth, rightDepth);
        return result;
            
    }

    int minDepth(TreeNode* root) {
        return getHeight(root);
    }
};


int main() {

    TreeNode* root =  new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(5);

    Solution solution;

    int result = solution.minDepth(root);

    cout << result << endl;

    return 0;
}
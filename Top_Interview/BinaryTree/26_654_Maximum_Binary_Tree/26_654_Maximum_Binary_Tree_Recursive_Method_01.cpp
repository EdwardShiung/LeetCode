#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
    [Question]
    You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

    Create a root node whose value is the maximum value in nums.
    Recursively build the left subtree on the subarray prefix to the left of the maximum value.
    Recursively build the right subtree on the subarray suffix to the right of the maximum value.
    Return the maximum binary tree built from nums.

    

        Example 1:

        Input: nums = [3,2,1,6,0,5]
        Output: [6,3,5,null,2,0,null,null,1]
        Explanation: The recursive calls are as follow:
        - The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
            - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
                - Empty array, so no child.
                - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
                    - Empty array, so no child.
                    - Only one element, so child is a node with value 1.
            - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
                - Only one element, so child is a node with value 0.
                - Empty array, so no child.

        Example 2:
        Input: nums = [3,2,1]
        Output: [3,null,2,null,1]

    [Thought]

    The question is almost the same with the LeetCode 106 & LeetCode 10.
    
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {};
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {};
};


class Solution {
private:


    // 利用 compared 找出陣列中，最大的值。並返回最大值在陣列中的下標。
    int compared(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            result = result >= nums[i] ? result : nums[i];
        }
        return result;
    }

    TreeNode* traversal(vector<int>& nums) {
        // 假如沒有任何的 node，return NULL
        if(nums.size() == 0) return NULL;
        // 如果有 node 在 nums 陣列中：
        // 找出陣列中的最大值
        int maxNum = compared(nums);
        // 找出最大值的下標
        int maxIndex;
        for(maxIndex = 0; maxIndex < nums.size(); maxIndex++) {
            if(maxNum == nums[maxIndex]) break;
        }
        // 將最大值作為 TreeNode Mid Node 節點
        TreeNode* root = new TreeNode(maxNum);
            // 終止條件：當只有一個節點時，直接返回 root;
        if(nums.size() == 1) return root;

            // 如果不止一個節點，繼續拆分 nums 陣列 (利用 TreeNode Mid Node)
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());

            // 遞歸循環
        root->left = traversal(leftNums);
        root->right = traversal(rightNums);

        return root;
    }

public:
    // construct Maximum Binary Tree
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums);
    }

    // 遍歷 TreeNode
    void printResult(TreeNode* root) {
        if (!root) {
            cout << "null";
            return;
        }

        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            
            if (node) {
                cout << node->val << " ";
                queue.push(node->left);
                queue.push(node->right);
            } else {
                cout << "null ";
            }
        }
    }
};

int main() {
    
    vector<int> nums = {3,2,1,6,0,5};

    Solution solution;

    TreeNode* result = solution.constructMaximumBinaryTree(nums);

    solution.printResult(result);

    
    return 0;
}
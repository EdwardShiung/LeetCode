#include <iostream>
#include <vector>
using namespace std;

/*

    The classic binary tree problem.
    Here I categorize the type of binary tree problem.
    1. Preorder Traversal --> LeetCode 144
    2. Inorder Traversal  --> LeetCode 94
    3. PostOrder Traversal --> LeetCode 145  

    [Review] 
    1. Review the 3 requirements in recursive method.
        - 確定 Recursive Function 參數 和 返回值
        - 終止條件
        - 確定單層邏輯
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:

    // 確定參數和返回值:
        // 因為要 print 出 遍歷順序，所以參數裡需要傳入 vector 來放節點的數值。
        // 不需要進一步處理數據，所以返回 void
    void traversal(TreeNode* cur, vector<int>& vec) {
    // 終止條件：當節點是空節點，代表本層遞歸結束。直接 return。
        if(cur == NULL) return;
    // 確定單層邏輯：
        // 中
        vec.push_back(cur->val);
        // 左
        traversal(cur->left, vec);
        // 右
        traversal(cur->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        traversal(root, results);
        return results;
    }
};

int main() {

    Solution solution;
    // 正確的創建樹的方法
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
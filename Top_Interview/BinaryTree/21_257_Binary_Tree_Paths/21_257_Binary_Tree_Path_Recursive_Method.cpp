#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
    [Question]
    Given the root of a binary tree, return all root-to-leaf paths in any order.

    A leaf is a node with no children.
        
        Example_01
           Input: root = [1,2,3,null,5]
           Output: ["1->2->5","1->3"]
        
        Example_02
            Input: root = [1]
            Output: ["1"]

    [Thought]
        本題觀念非常重要！！使用“Recursive Method”，經長也要使用 "Backtracking"
            --> Recursive 和 Backtracking 是對應的！有一個”遞歸“，就有一個”回朔“。
        
        1. 這題因為從 root 找尋路徑，所以要使用"前序"遍歷。
            --> 遍歷順序：中、左、右

        2. 本題，需要使用到 Backtracking
    
    [Review]
        1. Backtracking Review
        2. to_string function
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
private:

    // 參數及回傳值
        // 使用 path 去紀錄每一條路徑
        // 使用 result 去紀錄每一次的結果
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& results) {
        
        // 中
        path.push_back(cur->val);

        // 終止條件：本題終止條件，是找到葉子節點（cur 不為空，其左、右孩子為空，就找到葉子節點）
            // 題目有很細緻的處理，需要加上 "->" 符號
        if(cur->left == NULL && cur->right == NULL) {
            // 用來構建路徑圖的字串（為了達到題目要求）ex: Output: ["1->2->5","1->3"]
            string sPath;
            // 遍历路径中的节点（不包括最后一个节点）
                // 將暫存的 node 存為路徑 (因為每一個 node 值的型態為 int，需要轉換成 string)
            for(int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            // 添加最後一個節點 (在這邊添加的原因，在於，不需要加上箭頭)
            sPath += to_string(path[path.size() - 1]);
            // 將完整紀錄的路徑 sPath 放入 result中
            results.push_back(sPath);
            //返回，終止當前遞歸。已經達到葉子節點！！
            return;
        }

        // 中：--> 雖然題目是”前序“遍歷，但中間處理要放在上面（終止條件之前）。

        // 左：這邊使用“遞歸”，為了回到root，這邊要 backtracking
        if(cur->left) {
            traversal(cur->left, path, results);
            // Backtracking
            path.pop_back();
        }
        // 右：這邊使用“遞歸”，為了回到root，這邊要 backtracking
        if(cur->right){
            traversal(cur->right, path, results);
            // Backtracking
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        vector<int> path;
        if(root == NULL) return results;
        traversal(root, path, results);
        return results;
    }
};



int main() {

/*
    Example_01:
        Input: root = [1,2,3,null,5]
*/

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<string> results = solution.binaryTreePaths(root);

    // print the paths from the results
    for(string sPath: results) {
        cout << sPath << " ";
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;



/*  This question is very much worth reconsidering!! 
    By practicing it multiple times, you can truly understand the concept being tested.

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
        3. 本題，請多次練習，練習版本可以分為
            --> (✓)非簡略版本          (Recursive Method)  --> Recursive_Method_01.cpp
            --> (✓)簡略版本            (Recursive Method) -->  Recursive_Method_02.cpp
            --> 迭代法                 (Iterative Method) -->  Stack Method
                                                         --> "遞歸"能做的，"棧"也能做喔！
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
    vector<string> traversal(TreeNode* cur, string path, vector<string>& results) {
        // 中
        path += to_string(cur->val);
        // 終止條件
        if(cur->left == NULL && cur->right == NULL) {
            results.push_back(path);
            return results;
        }

        // 中：--> 雖然題目是”前序“遍歷，但中間處理要放在上面（終止條件之前）。

        // 左
        if (cur->left) {
            path += "->";
            traversal(cur->left, path, results); // 左
            path.pop_back(); // 回溯 '>'
            path.pop_back(); // 回溯 '-'
        }
        if (cur->right) {
            path += "->";
            traversal(cur->right, path, results); // 右
            path.pop_back(); // 回溯'>'
            path.pop_back(); // 回溯 '-'
        }
        return results;
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;

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
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
    2. 使用 hashmap 概念
        - map 的好處是，key value
            - 利用遍歷特性，將 node 每個值，出現的次數，記錄下來
            -  Key:     儲存值
            -  Value:   次數
    3. const auto&
        --> 為了確保不會動到 Key 值，所以使用 const 做保護
        --> auto 經常使用在 hashmap 遍歷中，自動型態確認
    4. & 引用使用，不用擔心效能問題
    
        pair.first 和 pair.second 是由 std::pair 類提供的。
        std::unordered_map（及其基礎類型 std::map）中的每個元素實際上是一個 std::pair，其中：
        first 是鍵（key），即映射中的鍵值對的鍵。
        second 是值（value），即映射中的鍵值對的值。

    5. 下面方法為 中序遍歷 ＋ Hash Map

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
        int maxCount = 0;

        // 使用 for-loop 遍歷所有的 map value，找尋次數最多的！
        // const auto&
            // const    代表不會修改這個值
            // auto     代表會根據實際類型自動轉換
            // &        使用引用方式，避免複製元素，提高效能
        for(const auto& pair: countMap) {
            if(pair.second > maxCount) {
                // 更新: 先將元素出現次數存放到 maxCount
                maxCount = pair.second;
                // 更新: result 陣列
                    // 更新前，要先清空，因為最多次數的出現了！！
                result.clear();
                result.push_back(pair.first);
                // 之所以會有 else if，就是因為次數最多的不一定只有一個
            }else if(pair.second == maxCount) {
                result.push_back(pair.first);
            }
        }
        return result;
    }
};

int main() {
    
    // TreeNode* root = new TreeNode(0);
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;

    vector<int> result = solution.findMode(root);

    for(int i: result) {
        cout << i << " ";

    }
    cout << endl;
    return 0;
}





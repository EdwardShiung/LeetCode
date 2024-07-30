#include <iostream>
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

    1. 本題解法有三種：
        - Recursive Method(In-order Method) + Hashmap
            - 這種解法屬於，如果沒有明確說二叉搜索樹，可以使用這種解法
            - 請看 01 檔案
        - Recursive Method (只使用 Recursive Method)
            - 題目明確說二叉搜索樹，因此可以使用二叉搜索樹的特性！
            - 二叉搜索樹必定用 L、M、R (中序)
            - 請看 02 檔案
        - Iterative Method

    2. 二叉搜索樹一定是中序遍歷
    3. 使用 hashmap 概念
        - map 的好處是，key value
            - 利用遍歷特性，將 node 每個值，出現的次數，記錄下來
            -  Key:     儲存值
            -  Value:   次數
    4. const auto&
        --> 為了確保不會動到 Key 值，所以使用 const 做保護
        --> auto 經常使用在 hashmap 遍歷中，自動型態確認
    5. & 引用使用，不用擔心效能問題
    
        pair.first 和 pair.second 是由 std::pair 類提供的。
        std::unordered_map（及其基礎類型 std::map）中的每個元素實際上是一個 std::pair，其中：
        first 是鍵（key），即映射中的鍵值對的鍵。
        second 是值（value），即映射中的鍵值對的值。

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
    // 利用 pre 指針來比較 cur 指針
    TreeNode* pre = NULL;

    // 利用 count 統計頻率
    int count = 0;

    // 利用 maxCount 找出最大頻率
    int maxCount = 0;

    // 利用 vector 存取 results (因為頻率最大的不一定只有一個)
    vector<int> results;

    void traversal(TreeNode* cur) {
        
        if(cur == NULL) return;
        
        // L
        traversal(cur->left);

        // M (中間處理)
        // pre node 先給予計算 count == 1。全部葉子節點，都先設定為 1。
        if(pre == NULL) {
            count = 1;
        // 如果 前一個節點，與下一個節點值相同，則 count++
        }else if(pre->val == cur-> val) {
            count++;
        // 如果 前一個節點，與下一個節點值不同，則設定為 1    
        }else{
            count = 1;
        }
        
        // 每一次遞歸都要讓 pre 指針往前移一個 node
        pre = cur;

        // [重點_01] 如果 遞歸發現 count 的值 == maxCount 的值，則可以將 node 的值，放到 results
            // 這也說明，為什麼頻率最大的，不一定只有一個
            // [注意]：也因為這一步，下一步要寫出，當 count 值 > maxCount 值，代表有更高的頻率出現。
        if (count == maxCount) results.push_back(cur->val);

        // [重點_02]
        if(count > maxCount) {
            
        // 因為出現頻率更高的值:
            // 更新 maxCount
            maxCount = count;
            // 所以清空 results
            results.clear();
            // 將值放入results
            results.push_back(cur->val);
        }
        // R
        traversal(cur->right);

    }

    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return results;
    }
};
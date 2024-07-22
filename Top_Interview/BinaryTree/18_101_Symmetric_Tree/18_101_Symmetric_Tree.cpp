#include <iostream>
#include <queue>
using namespace std;

/*

    [Thoughts]
    1. Recursive Method
    2. Understanding the character "&"

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0)  , left(nullptr), right(nullptr){};
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr) {};
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {};
};


class Solution {
public:

    bool compare(TreeNode* left, TreeNode* right) {
        // Step_01 先比較是否有空節點
        if(left == NULL && right != NULL) return false;
        else if(left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // Step_01 並且也排除節點 vale 不同
        else if(left->val != right->val) return false;

        // Step_02 當左右節點不為空的情況下，開始做下一層的判斷
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return compare(root->left, root->right);
    }

/*

    這是因為 vector<int>& vec 是引用傳遞，而 vector<int> vec 是值傳遞。兩者的區別如下：

    引用傳遞 (vector<int>& vec):

    傳遞的是參考，即函數內部操作的是原始的向量，並不會產生副本。
    修改 vec 會直接影響到傳入的原始向量。
    可以避免拷貝整個向量，節省記憶體和時間。
    值傳遞 (vector<int> vec):

    傳遞的是向量的副本，即函數內部操作的是傳入向量的一個拷貝，原始向量不會被修改。
    修改 vec 只會影響到函數內部的副本，函數結束後副本會被銷毀，對原始向量無影響。
    需要拷貝整個向量，會消耗額外的記憶體和時間。

    在這個情況下，traversal 函數的目的是在遍歷二叉樹的過程中不斷地將節點的值加入到向量 vec 中。
    如果使用值傳遞，每次函數呼叫都會創建 vec 的副本，並且對副本的修改不會反映到原始的向量中，最終結果會丟失。
    因此，使用引用傳遞是必要的，以便在函數內部對 vec 的修改能夠保留到函數外部。

*/
    void traversal(TreeNode* cur, vector<int>& vec) {
        // 確定終止條件
        if(cur == NULL) return;
        // 確定單層邏輯
            // 左
            traversal(cur->left, vec);
            // 右
            traversal(cur->right, vec);
            // 中
            vec.push_back(cur->val);    
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        traversal(root, results);
        return results;
    }
};

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    vector<int> results = solution.postorderTraversal(root);

    for(int i : results) {
        cout << i << " ";
    }
    cout << endl;   
    
    return 0;

}
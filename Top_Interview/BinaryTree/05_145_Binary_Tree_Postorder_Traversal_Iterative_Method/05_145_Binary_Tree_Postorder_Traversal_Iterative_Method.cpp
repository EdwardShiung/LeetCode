#include <iostream>
#include <stack>
using namespace std;


/*

    The classic binary tree problem.
    Here I categorize the type of binary tree problem.
    1. Preorder Traversal --> LeetCode 144
    2. Inorder Traversal  --> LeetCode 94
    3. PostOrder Traversal --> LeetCode 145  

    [Iterative Method]
        Binary Tree also can use iterative method.
        The process is just like using a stack structure.
    [Key Point]
        Postorder Traversal : Left -> Right -> Middle
            --> I use the same concept from LeetCode 144 Preorder Traversal, 
            which means that it could adjust the right & left and "reverse" to get the answer.

        Preorder Traversal   Change "R & L" to "L & R"                         Reverse   Postorder Traversal
        M ----> L ----> R   --------------------------> M ----> R -----> L -------------> L ----> R ----> M

*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // Create a results
        vector<int> results;
        // Create a stack
        stack<TreeNode*> stack;

        // put the root to the stack (if root == NULL return results)
        if(root == NULL) return results;
        
        // if root != Null
        stack.push(root);

        // Using Stack to make the preorder traversal
        // if the stack don't have any Node, it will stop the while-loop.
        while(!stack.empty()) {
            // using a pointer to point the top value in the stack
            TreeNode* node = stack.top();
            // pop out the top value
            stack.pop();
            // Put the value to the result
            results.push_back(node->val);
            // Again, put the node chile to the stack
            // Before putting the child to the stack, we need to make sure there is a value in the left or right child.
            // Put the "Left" first, and then put "Right"
                // Left
            if(node->left) stack.push(node->left);
                // right
            if(node->right) stack.push(node->right);
        }

        reverse(results.begin(), results.end());
        return results;
    }
};


int main() {
    // import class Soluion
    Solution solution;
    // results variable
    vector<int> results;
    // Create TreeNode
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    results = solution.postorderTraversal(root);

    for(int i : results) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*

[Note]
    - reverse function
        Understanding how to use C++ Library std::reverse function
    
    - Q_01: Other Knowledge: How can you differentiate Library, API, Method, function?
    - Q_02: Using C++, sometimes we use ::, but sometime write :

    C++ 標準庫 (Standard Library) 包含了許多不同類型的功能和工具，可以大致分為以下幾個主要部分：

        1. **容器 (Containers)**：用來存儲和管理資料的資料結構。例如：
            - `std::vector`
            - `std::list`
            - `std::deque`
            - `std::set`
            - `std::map`

        2. **演算法 (Algorithms)**：一組操作容器中資料的通用函式。例如：
            - `std::sort`
            - `std::reverse`
            - `std::find`
            - `std::accumulate`

        3. **迭代器 (Iterators)**：一組對容器中的元素進行遍歷的工具。例如：
            - `std::iterator`
            - `std::begin`
            - `std::end`

        4. **函式物件和 Lambda 表達式 (Function Objects and Lambda Expressions)**：用來封裝可呼叫物件的工具。例如：
            - `std::function`
            - `std::bind`
            - Lambda 表達式 (`[](){}`)

        5. **實用工具 (Utilities)**：包括一組通用工具類別和函式。例如：
            - `std::pair`
            - `std::tuple`
            - `std::optional`
            - `std::any`

        6. **記憶體管理 (Memory Management)**：管理動態記憶體分配的工具。例如：
            - `std::unique_ptr`
            - `std::shared_ptr`
            - `std::weak_ptr`

        7. **多執行緒和同步 (Multithreading and Synchronization)**：用來支援多執行緒程式設計的工具。例如：
            - `std::thread`
            - `std::mutex`
            - `std::condition_variable`

        8. **字串和流 (Strings and Streams)**：用來處理字串和 I/O 操作的工具。例如：
            - `std::string`
            - `std::stringstream`
            - `std::ifstream`
            - `std::ofstream`

        9. **數學和數值演算法 (Mathematics and Numerical Algorithms)**：提供數學函式和數值演算法的工具。例如：
            - `std::cmath`
            - `std::complex`
            - `std::valarray`

        10. **日期和時間 (Date and Time)**：用來處理日期和時間的工具。例如：
            - `std::chrono`

        11. **標準範例 (Standard Exception)**：一組用來處理異常的類別。例如：
            - `std::exception`
            - `std::runtime_error`
            - `std::out_of_range`

    這些組成部分共同構成了 C++ 標準庫，提供了廣泛的功能和工具，幫助開發者有效地進行程式設計。
        
    上述組成部分中有些是自由函式庫，有些則是類別庫。讓我們更詳細地分類：

    ### 自由函式庫（Free Function Libraries）
    這些庫主要由自由函式（不屬於任何類別的函式）組成，通常提供泛型演算法和工具函式。

    1. **演算法 (Algorithms)**：自由函式，例如 `std::sort`、`std::reverse`、`std::find` 等。
    2. **迭代器 (Iterators)**：雖然有一些類別，但大部分是用來操作迭代器的自由函式，例如 `std::begin`、`std::end`。
    3. **數學和數值演算法 (Mathematics and Numerical Algorithms)**：主要是自由函式，例如 `std::sqrt`、`std::pow`、`std::accumulate` 等。
    4. **記憶體管理 (Memory Management)**：有些是自由函式，例如 `std::allocator_traits` 中的成員函式。
    5. **標準範例 (Standard Exception)**：提供一些自由函式來處理異常。

    ### 類別庫（Class Libraries）
    這些庫主要由類別組成，提供面向對象的接口。

    1. **容器 (Containers)**：類別，例如 `std::vector`、`std::list`、`std::map` 等。
    2. **函式物件和 Lambda 表達式 (Function Objects and Lambda Expressions)**：包括類別和類別模板，例如 `std::function`、`std::bind`。
    3. **實用工具 (Utilities)**：包括 `std::pair`、`std::tuple`、`std::optional` 等類別。
    4. **記憶體管理 (Memory Management)**：包括 `std::unique_ptr`、`std::shared_ptr`、`std::weak_ptr` 等智能指針類別。
    5. **多執行緒和同步 (Multithreading and Synchronization)**：包括 `std::thread`、`std::mutex`、`std::condition_variable` 等類別。
    6. **字串和流 (Strings and Streams)**：包括 `std::string`、`std::stringstream`、`std::ifstream`、`std::ofstream` 等類別。
    7. **日期和時間 (Date and Time)**：包括 `std::chrono` 中的各種類別，例如 `std::chrono::duration`、`std::chrono::time_point`。

    ### 混合庫（Mixed Libraries）
    這些庫既包含自由函式，也包含類別。

    1. **字串和流 (Strings and Streams)**：既有 `std::string` 類別，也有很多與 I/O 操作相關的自由函式。
    2. **多執行緒和同步 (Multithreading and Synchronization)**：既有 `std::thread` 等類別，也有 `std::this_thread::sleep_for` 等自由函式。

    總結來說，C++ 標準庫既包含了自由函式，也包含了類別，根據不同的功能和用途進行分類和組合。

-->ANS_01:  因此：

    `reverse` 函式是 C++ 標準庫中的一個函式，屬於 `<algorithm>` 標頭檔案。它不是某個類別的成員函式，而是自由函式（free function）。

    以下是 `std::reverse` 的基本使用方法：

    ```cpp
    #include <algorithm>  // 引入 <algorithm> 標頭檔案
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};

        // 使用 std::reverse 函式反轉向量的元素
        std::reverse(vec.begin(), vec.end());

        for (int i : vec) {
            std::cout << i << " ";
        }

        return 0;
    }
    ```

    在這個例子中，`std::reverse` 函式來自於 `<algorithm>` 標頭檔案，用來反轉一個範圍內的元素。它是一個模板函式，可以用於不同類型的容器或範圍。

    因此，`reverse` 函式屬於 C++ 標準庫的 `<algorithm>` API 集合，而不是某個類別的成員函式。


*/
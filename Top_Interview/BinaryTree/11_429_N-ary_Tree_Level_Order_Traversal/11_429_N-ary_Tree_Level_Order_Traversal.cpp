#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    The classic binary tree problem for "level order traversal" using "queue method".
    Here I categorize the type of level order traversal.
    1. LeetCode 102
    2. LeetCode 107
    3. LeetCode 199
    4. LeetCode 637
    *5. LeetCode 429 
    6. LeetCode 515
    7. LeetCode 116
    8. LeetCode 117
    9. LeetCode 104
    10.LeetCode 111 

    Above question could use "Level of Traversal Method" and "Recursive Method".

    [Review]
    1. OOP--> How to create the N-ary Node by class
    2. How to create the N-ary Node by struct
*/

class Node {
    int val;
    vector<Node*> children;

    // 默認構造函數。這個構造函數不帶任何參數，創建一個值和孩子節點都為空的節點。
    Node() {}

    // 帶一個參數的構造函數。這個構造函數接收一個整數 _val，並將其賦值給節點的 val 屬性，孩子節點默認為空。
    Node(int _val) {
        val = _val;
    }

    // 帶兩個參數的構造函數。
    // 這個構造函數接收一個整數 _val 和一個 Node 指針的向量 _children。它們分別用來初始化節點的 val 和 children 屬性。
    Node(int _val, vector<Node*> _children) {
        val = val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // Create a results vector
        vector<vector<int>> results;
        // Because we need to do level of traversal, queue will be a good strategy to do that.
        queue<Node*> queue;
        // if root == null, return results directly
        if(root == NULL) return results;
        // if root != NULL, put root into queue
        queue.push(root);

        // while-loop to do the level order of traversal
        while(!queue.empty()) {
            // Each layer of size (Getting how many nodes in the same layer!)
            int size = queue.size();
            // Using vector to story the layer of nodes
            vector<int> vec;
            // for-loop search the node in the same level
            for(int i = 0; i < size; i++) {
                // Using pointer to point the node
                Node* curr = queue.front();
                // let the node of value into the vec
                vec.push_back(curr->val);
                // pop the node from the queue
                queue.pop();
                // keep search the child node from the curr node
                for(int j = 0; j < curr->children.size(); j++) {
                    if(curr->children[j]) queue.push(curr->children[j]);
                }
            }
            results.push_back(vec);
        }
        return results;
    }
};
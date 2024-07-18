#include <iostream>
#include <queue>
using namespace std;

/*
[Similar Question]
    The question is the same concept with LeetCode 116, so scan the node concept is the same.
        --> Using level order traversal method.
    LeetCode 116 is for perfect Binary Tree.
    LeetCode 117 is for complete Binary Tree.
  1. The question is similar with LeetCode 117.


*/


struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {};
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {};
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {};
};

class Solution {
public:
    Node* connect(Node* root) {
        // Create a queue to assist level order traversal
        queue<Node*> queue;
        // if root != null, put the root into the queue
        if(root != nullptr) queue.push(root);
        // Using while-loop for level order traversal
        while(!queue.empty()) {
            // Record each layer of size of node
            int size = queue.size();
            // Using the preNode pointer to record the preNode
            Node* preNode;
            // Using the Node to point the current node
            Node* node;
            // Using for-loop to scan the same layer of node
            for(int i = 0; i < size; i++) {
                // Get the first node in the same layer
                if(i == 0) {
                    preNode = queue.front();
                    queue.pop();
                    node = preNode;
                }else{
                    node = queue.front();
                    queue.pop();
                    preNode->next = node;
                    preNode = preNode->next;
                }
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            preNode->next = nullptr;
        }
        return root;
    }
};
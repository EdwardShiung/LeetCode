#include <iostream>
#include <queue>
using namespace std;

/*
You are given a perfect binary tree where all leaves are on the same level, 
and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.


Example_01
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. 
The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

*/

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {};
    Node(int _val): val(_val), left(nullptr), right(nullptr), next(nullptr){};
    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {};
};

/*
  [Similar Question]
  1. The question is similar with LeetCode 117.
  [Review]
    1. 上述 Constructor 中，可以看到有些有下底線，有些沒有。這是用來區分哪些是成員函數、
    哪些是參數函數。
      -  val、left、right、next     是類別中的成員變量
      -  _val、_left、_right、_next 是建構函式中的參數變量

    - 避免命名衝突：如果成員變量和參數變量名稱相同，可能會導致混淆。
      例如，如果參數變量和成員變量都叫val，在建構函式內部，使用val時究竟是指參數還是成員變量就不明確了。
      通過給參數變量添加下底線，可以清楚地區分兩者。
    
    - 提高可讀性：當看到參數名稱中有下底線時，讀者可以立即知道這是個參數變量，而不是成員變量。

    - 符合編程規範：在一些編程規範中，會建議使用這種命名方式來提高代碼的可維護性和可讀性。
*/


class Solution {
public:
    Node* connect(Node* root) {

      // Create a queue for assist level order traversal
      queue<Node*> queue;
      
      // if root == nullptr, return result
      if(root == nullptr) return root;

      // if root != nullptr, 
      queue.push(root);

      // while-loop to do the level order traversal
      while(!queue.empty()) {
        // Each layer of size (Getting how many nodes in the same layer)
        int size = queue.size();

        // Using PreNode & Node to traversal the same layer 
          // Using Pointer to point the pre-Node
        Node* preNode;
          // Using the Pointer to point the current Node
        Node* node;

        // for-loop to scan each of node in the same layer
        for(int i = 0; i <  size; i++) {
          if(i == 0) {
            // Get the first node (root)
            preNode = queue.front();
            // Pop the node from the queue
            queue.pop();
            // the first node (preNode) == node
            node = preNode;
          }else{
            // else part: handle the node after the first node
            node = queue.front();
            queue.pop();

            // let preNode point to the node
            preNode->next = node;
            // 移動 preNode (例如到了第二層之後，每一層都有無數個節點，所以處理完，要移動 preNode)
            preNode = preNode->next;
          }
          // handle the next level of layer
          if(node->left) queue.push(node->left);
          if(node->right) queue.push(node->right);
        }
        // handle the last node (whole tree)
        preNode->next = nullptr;
      }
      return root;
    }
};

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);


  Solution solution;
  Node* results = root;
  results = solution.connect(root);

  queue<Node*> treeAssist;
  treeAssist.push(results);
  while(!treeAssist.empty()) {
    int size = treeAssist.size();
    // Using a temp to store the value
    Node* temp;
    for(int i = 0; i < size; i++) {
      temp = treeAssist.front();
      treeAssist.pop();

      temp->val ? cout << temp->val << " " : cout << "#" << " ";

      // put the child node to the queue for next layer
      if(temp->left) treeAssist.push(temp->left);
      if(temp->right) treeAssist.push(temp->right);
    }
    cout << "# ";
  }
  cout << endl;
}
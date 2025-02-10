/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.

[Reference]:
    https://www.youtube.com/watch?v=2IvGT0PMbDk
    https://fufuleetcode.github.io/2019/08/21/lc-133/
    
[Thought]:
    1. 本題可以作為 Graph 的基礎題
        - DFS - 可以說是一個 Stack 過程
        - BFS - 透過 queue 過程

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    // (1) 無參數構造函數
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    // (2) 單參數構造函數（初始化節點值）
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    // (3) 雙參數構造函數（初始化節點值 + 鄰居節點）
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // 利用 hashmap: key 為原本 node , value 為 copied node
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        // Edge Cases
        if (!node) return NULL;

        // If copied, return visited
        if (visited.count(node)) return visited[node];

        // If not copied, there are two steps.
        // 1st: Create the node
        Node* node_copy = new Node(node->val);
        visited[node] = node_copy;

        // 2nd: Connect the neighbor by recursion
        for(Node* neighbor: node->neighbors) {
            node_copy->neighbor.push_back(dfs(neighbor, visited));
        }
        return node_copy;
    }
};


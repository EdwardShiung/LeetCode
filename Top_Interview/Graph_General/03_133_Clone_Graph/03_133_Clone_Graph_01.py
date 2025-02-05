'''

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
'''


'''
[Reference]:
    https://www.youtube.com/watch?v=2IvGT0PMbDk
    
[Thought]:
    1. 本題可以作為 Graph 的基礎題
        - DFS - 可以說是一個 Stack 過程
        - BFS - 透過 queue 過程
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        visited = dict()    # Key = node, Value = copied node

        def dfs(node: "Node", visited:dict) -> 'Node':
            """
            copy the entire graph connected to node, and return the node
            """

            # Step_00: Edge Cases
            if not node: return None

            # Step_01: if node is already copied
            if node in visited:
                return visited[node]
            # Step_02: if the node is not copied

                # Step_02_01: Copied the node
                        # 生成一個新的節點，並且讓這個新生節點的值 等於原始的值
            node_copy = Node(node.val)
                        # 再將這個新生的節點，添加到“已訪問”的節點中
            visited[node] = node_copy
                # Step_02_02: Recursively copied the neighbors
                        # 對每一個節點，進行訪問
            for neighbor in node.neighbors:
                        # 利用 dfs 去做 recursion
                neighbor_copy = dfs(neighbor, visited)
                # Step_02_03: Build the Eage from node_copied to neighbors
                visited[node].neighbors.append(neighbor_copy)
            return visited[node]
        return dfs(node, visited)
        
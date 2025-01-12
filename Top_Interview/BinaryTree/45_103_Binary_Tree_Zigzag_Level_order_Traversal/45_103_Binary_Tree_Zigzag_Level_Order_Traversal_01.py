'''
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

'''
from typing import Optional, List
from collections import deque

class TreeNode:
    def __init__ (self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # Edge Case
        if not root:
            return []
        
        res = []
        # Using the deque to assist the process
        dq = deque()
        dq.append(root)
        
        # Direction Setting (Default: Left to Right)
        left_to_right = True
        
        while dq:
            # Using a level_node array to store layer node
            level_node = []
            # Record the number of node in each layer
            level_size = len(dq)
            # Using the for-loop to store nodes in each layer
            for i in range(level_size):
                if left_to_right:
                    node = dq.popleft()
                    if node.left: 
                        dq.append(node.left)
                    if node.right:
                        dq.append(node.right)
                else:
                    node = dq.pop()
                    if node.right:
                        dq.appendleft(node.right)
                    if node.left:
                        dq.appendleft(node.left)
                # Store the each layer or node value
                level_node.append(node.val)
            
            # Store the layer node to result
            res.append(level_node)
            # Change the Direction
            left_to_right = not left_to_right

        return res
        
        
'''
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:

Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
'''
from typing import Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> list[int]:
        # Using a res variable to store the outcome
        res = []
        # Using a deque to process the solution
        '''
        dq = deque([root])
        等同於：
        dq = deque()
        dq.append(root)
        '''
        dq = deque([root])
        
        while dq:
            # Track the the most right side node from deque
            rightSide = None
            # Record each layer of node
            dqLen = len(dq)
            
            for i in range(dqLen):
                node = dq.popleft()
                if node:
                    rightSide = node
                    if node.left:
                        dq.append(node.left)
                    if node.right:
                        dq.append(node.right)
            if rightSide:
                res.append(rightSide.val)
        
        return res
            
            
            
            
        
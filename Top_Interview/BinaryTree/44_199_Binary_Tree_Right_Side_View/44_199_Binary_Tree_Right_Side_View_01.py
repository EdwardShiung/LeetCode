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
        # Edge Case
        if not root:
            return []
        # Using a result to store the outcome
        res = []
        # Using the deque to handle the problem
        dq = deque([root])
        
        while dq:
            # 用來記錄當前最右邊的值
            rightSide = None
            dqLen = len(dq)
            
            '''
            這部分也可以這樣寫，不用去判斷 node.left 和 node.right。
            原因在於，放進去如果為空值，將再下一次循環中，assign 到 node 的值，進行判斷
            
            for i in range(dqLen):
                node = dq.popleft()
                if node:
                    rightSide = node
                    
                    dq.append(node.left)
                    dq.append(node.right)
            '''
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
    
sol = Solution()
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(5)
root.right.right = TreeNode(4)
result = sol.rightSideView(root)

for i in range(len(result)):
    print(result[i])
        
        
        
        
        
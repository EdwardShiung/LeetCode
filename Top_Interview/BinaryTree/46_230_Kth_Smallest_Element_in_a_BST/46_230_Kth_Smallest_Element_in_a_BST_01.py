'''
Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 
Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., 
we can do insert and delete operations) and you need to find the kth smallest frequently, 
how would you optimize?

[Thought]:
1. 本題"DFS"且用 Recursive Method 的 Inorder Method
'''
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k:int) ->int:

        # Using a nodeList to store the node by sequence
        # from the bottom to the top
        # inorder sequence
        nodeList = []

        # Using the helper function to process the sequence
        self.helper(root, nodeList)
        
        return nodeList[k - 1]
        
        # Using a helper function to do the recursive
        
    def helper(self, node: Optional[TreeNode], nodeList: List[int]):
        # Edge Case:
        if not node:
            return 
        self.helper(node.left, nodeList)
        nodeList.append(node.val)
        self.helper(node.right, nodeList)


sol = Solution()

root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)

k = 1

result = sol.kthSmallest(root, k)
print(result)
        
        
            

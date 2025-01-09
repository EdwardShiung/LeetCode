'''
Given two integer arrays preorder and inorder 
where preorder is the preorder traversal of a binary tree and 
inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.


[Reference Link]:
https://www.youtube.com/watch?v=ihj4IQGZ2zc

[Thought]:
    1. Always starting from the preorder traversal.
    2. After pick the node from the preorder traversal, we could separate the left and right part
    3. This is the recursive method, so we need to start base case in our code.
'''

# Construct a TreeNode
class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: list[int], inorder: list[int]) -> Optional[TreeNode]:
        # Base Case
        if not preorder or not inorder:
            return None
        
        # Construct a Tree root by set the 1st node to the root
        root = TreeNode(preorder[0])
        # mid 是根節點在中序遍歷中的索引位置
        mid = inorder.index(preorder[0])
        # Python 的好處是，可以直接使用 subarray
        # 根據索引切割中序遍歷，並遞歸構建左右子樹
        # 這部分直接 skip 掉 index = 0，原因在於 index = 0 已經在 root
        root.left = self.buildTree(preorder[1:mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
        
        return root
    
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
result = Solution().buildTree(preorder, inorder)

print(result)
        
        

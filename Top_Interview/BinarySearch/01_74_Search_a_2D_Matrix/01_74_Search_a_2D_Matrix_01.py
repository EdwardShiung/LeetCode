'''
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

[Thought]
1. 本題不要想 2D 矩陣，而是想成一維陣列

'''
from typing import List
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # Edge Case
        if not matrix or target is None:
            return False
        # Get the boundary
        rows = len(matrix)
        cols = len(matrix[0])
        
        low = 0
        high = rows * cols - 1
        
        while low <= high:
            # Python 使用 "//" 代表整數除法
            mid = (low + high) // 2
            num = matrix[mid // cols][mid % cols]
            
            if num == target:
                return True
            elif num < target:
                low = mid + 1
            elif num > target:
                high = mid - 1
        
        return False
    
sol = Solution()
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
target = 3

result = sol.searchMatrix(matrix, target)
print(result)
        
    
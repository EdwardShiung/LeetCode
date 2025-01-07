'''
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

[Reference Link]:
    https://www.youtube.com/watch?v=BJnMZNwUk1M

'''

class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        # Edge Case
        # 假如不是 matrix 或者 為空陣列，返回[]
        if not matrix or not matrix[0]:
            return []
        
        # Store the result
        result = []
        
        # Set the Boundaries
        left = 0
        right = len(matrix[0])
        top = 0
        bottom = len(matrix)
        
        while left < right and top < bottom:
            # get every i in the top row
            # From left to right
            for i in range(left, right):
                result.append(matrix[top][i])
            top += 1
            
            # get every i in right column
            # From top to down
            for i in range(top, bottom):
                result.append(matrix[i][right - 1])
            right -= 1
            
            '''
            加入這段條件的主要原因是為了在邊界更新後，
            提前檢查是否還需要繼續處理剩餘的矩陣範圍，
            並在不需要時立即結束迴圈，避免不必要的運算。
            '''
            if not (left < right and top < bottom): 
                break
            
            # get every i in bottom row
            # From right to left
            for i in range(right - 1, left - 1, -1):
                result.append(matrix[bottom - 1][i])
            bottom -= 1
            
            # get every i in left column
            # From down to top
            for i in range(bottom - 1, top - 1, -1):
                result.append(matrix[i][left])
            left += 1
        
        return result
    
    
sol = Solution()

martix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

result = sol.spiralOrder(martix)

print(result)

        
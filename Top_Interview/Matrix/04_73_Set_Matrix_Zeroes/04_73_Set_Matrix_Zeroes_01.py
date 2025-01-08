'''
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


[Reference Link]:
https://www.youtube.com/watch?v=T41rL0L3Pnw

[Solutions]:
1. Create a copied matrix. --> SC = O(m*n)
2. Using two array: one is for row, the other one is for column. --> SC = O(m + n), TS(m*n)*3
3. Set the inner row and column in matrix with one temp variable for [top][left]  --> SC(1)


[[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]]
[1, 2, 3, 4]
[5, 0, 7, 8]
[0,10,11,12]
[13,14,15,0]

'''

class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        # Boundaries
        ROWS = len(matrix)
        COLS = len(matrix[0])
        
        # Marks 1st row and column
        first_row_has_zero = False
        first_col_has_zero = False
        
        # Determine if the first row need to be zero
        for c in range(COLS):
            if matrix[0][c] == 0:
                first_row_has_zero = True
        
        # Determine if the first column need to be zero
        for r in range(ROWS):
            if matrix[r][0] == 0:
                first_col_has_zero = True
        
        # Update the partial row and column by other matrix
        for r in range(1, ROWS):
            for c in range(1, COLS):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0
                    matrix[r][0] = 0

        # Update the rest of the matrix based on 1st row and 1st column
        for r in range(1, ROWS):
            for c in range(1, COLS):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0
                    
        # Update the 1st row and 1st column by marks
        if first_col_has_zero:
            for r in range(ROWS):
                matrix[r][0] = 0
                
        if first_row_has_zero:
            for c in range(COLS):
                matrix[0][c] = 0
        
        
        
        




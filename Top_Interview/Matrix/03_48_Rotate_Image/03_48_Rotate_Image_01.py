'''
You are given an n x n 2D matrix representing an image, 
rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, 
which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

 
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000


[Reference Link]:
1.https://www.youtube.com/watch?v=fMSJSS7eO1w&list=PL-CpLXmniLM0EJ7FUPIK78KOyYG2xoKM5

TC = o(n^2)
SC = o(1)

'''

class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # Boundaries
        left = 0
        right = len(matrix) - 1
        
        while left < right:
            for i in range(right - left):
                
                # Boundaries for Top and Bottom
                top = left
                bottom = right
                
                # Save the 1st [top][left] element
                tmp = matrix[top][left + i]
                
                # counter clockwise
                    # move the [bottom][Left] into [top][Left]
                matrix[top][left + i] = matrix[bottom - i][left]
                
                    # move the [bottom][right] into [bottom][left]
                matrix[bottom - i][left] = matrix[bottom][right - i]
                
                    # move the [top][right] into [bottom][right]
                matrix[bottom][right - i] = matrix[top + i][right]
                
                    # move the [top][left] into [top][right]
                matrix[top + i][right] = tmp
            right -= 1
            left += 1
                
                
                
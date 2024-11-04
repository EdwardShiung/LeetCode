#include <iostream>
using namespace std;


/*
You are given an m x n integer array grid. 
There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. 
A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example_01:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right


*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Calculate the col
        int col = obstacleGrid.size();
        // Calculate the row
        int row = obstacleGrid[0].size();
        // Basic Limitation (If starting point or ending point is obstacle, return 0)
        if(obstacleGrid[0][0] || obstacleGrid[col - 1][row - 1]) return 0;
        // Using Loop to calculate first row and first col (Initialization)
        vector<vector<int>> dp(col, vector<int>(row, 0));
        for(int i = 0; i < col && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for(int j = 0; j < row && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;

        for(int i = 1; i < col; i++) {
            for(int j = 1; j < row; j++) {
                if(obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[col - 1][row - 1];
    }
};
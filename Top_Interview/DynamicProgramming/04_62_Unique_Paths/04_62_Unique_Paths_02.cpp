#include <iostream>
using namespace std;

/*
There is a robot on an m x n grid. 
The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, 
return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

[Thought]:
    1.  Using the DFS to iterative all of the nodes.
        - Time Limited Exceed
    2.  Using the DP method
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Using DP, we have to record each square about the status
        // Step_01: Define the dp[i][j]
            // (i, j) == (0, 0) to (m, n)
            // which means that from (0, 0) to (m, n) have lots of paths(路徑)--> 不是“步數” 
        // Step_02: DP Formula
            // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        // Step_03: Initialize the dp[i][j]    
            // Example in first row: dp[0][j]
                        //first col: dp[i][0]
        vector<vector<int> > dp(m, vector<int>(n, 0));
            // Initialize column (m)
        for(int i = 0; i < m; i++) dp[i][0] = 1;
            // Initialize row (n)
        for(int j = 0; j < n; j++) dp[0][j] = 1;
        // Loop each of square
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    int results = solution.uniquePaths(3, 2);
    printf("%d", results);
    return results;
}
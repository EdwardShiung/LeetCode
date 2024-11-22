#include <iostream>
using namespace std;



/*
You are given two integers m and n representing a 0-indexed m x n grid. 
You are also given two 2D integer arrays guards and walls 
where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position 
unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.

Example 1:
Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
Output: 7
Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
There are a total of 7 unguarded cells, so we return 7.

Example 2:
Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
Output: 4
Explanation: The unguarded cells are shown in green in the above diagram.
There are a total of 4 unguarded cells, so we return 4.

Constraints:

1 <= m, n <= 105
2 <= m * n <= 105
1 <= guards.length, walls.length <= 5 * 104
2 <= guards.length + walls.length <= m * n
guards[i].length == walls[j].length == 2
0 <= rowi, rowj < m
0 <= coli, colj < n
All the positions in guards and walls are unique.

    [Thought]
    [Solution_01]
    1. Review grid in C++
        - 2 Dimension Array
        Complexy: Time O(m * n) & Space O(m * n)
    
    [Soltion_02]
    1. Try to use labmbda
*/

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // create a grid m x n with default value zero
        vector<vector<int>> grid(m, vector<int>(n, 0));
        /*
            0 = free
            1 = guard
            2 = wall
            3 = guardable
        */
        
        // Based on the guards, place the guard in the grid
        for(const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }

        // Based on the walls, place the wall in the grid
        for(const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }

        // Using Lambda to change the value in grid
        // C++ 11
        auto mark_guarded = [&](int r, int c) {
        // From one of guardable blocks
        // to down
            for(int row = r + 1; row < m; row++) {
                if(grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
            // to up
            for(int row = r - 1; row >= 0; row --) {
                if(grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
            // to right
            for(int col = c + 1; col < n; col++) {
                if(grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }
            // to left
            for(int col = c - 1; col >= 0; col--) {
                if(grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;   
            }
        };

        // Mark Guarded Block by each guarded block
        for(const auto& guard : guards) {
            mark_guarded(guard[0], guard[1]);
        }

        // Calculate the free blocks
        int total = 0;
        for(const auto& row : grid) {
            for(int block : row) {
                if(block == 0) total++;
            }
        }

        return total;
    }

// private:
//     // Mark Guarded Function
//     void mark_guarded(vector<vector<int>>& grid, int m, int n, int r, int c) {
//         // From one of guardable blocks
//         // to down
//         for(int row = r + 1; row < m; row++) {
//             if(grid[row][c] == 1 || grid[row][c] == 2) break;
//             grid[row][c] = 3; 
//         }
//         // to up
//         for(int row = r - 1; row >= 0; row --) {
//             if(grid[row][c] == 1 || grid[row][c] == 2) break;
//             grid[row][c] = 3;
//         }
//         // to right
//         for(int col = c + 1; col < n; col++) {
//             if(grid[r][col] == 1 || grid[r][col] == 2) break;
//             grid[r][col] = 3;
//         }
//         // to left
//         for(int col = c - 1; col >= 0; col--) {
//             if(grid[r][col] == 1 || grid[r][col] == 2) break;
//             grid[r][col] = 3;   
//         }
//     }
};
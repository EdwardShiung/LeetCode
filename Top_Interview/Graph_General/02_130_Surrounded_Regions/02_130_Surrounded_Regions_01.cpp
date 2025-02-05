/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

/*
 [Thought]:
  1. 思考 'O' 不能被圍住
    --> 必定跟邊界有關
        --> 所以先處理周邊

    For example,
    Row 01  X X X X
    Row 02  X O O X
    Row 03  X X O X
    Row 04  X O X X
*/
#include <iostream>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        // m 代表 lastRow
        // n 代表 lastCol
        int m = board.size() - 1;
        int n = board[0].size() - 1;

        // Step_01: [先處理周圍]
        // 處理 列 Column
        for(int i = 0; i <= m; i++) {
            // 第一列
            if(board[i][0] == 'O') dfs(board, i, 0);
            // 最後一列
            if(board[i][n] == 'O') dfs(board, i, n);
        }
        // 處理 行 Row
        for(int i = 0; i <= n; i++) {
            // 第一行
            if(board[0][i] == 'O') dfs(board, 0, i);
            // 最後一行
            if(board[m][i] == 'O') dfs(board, m, i);
        }

        // Step_02[處理內部為 'O' 及 '1']
        // 內部若為 'O' --> 改成 'X'
        // 內部若為 '1' --> 改成 'O'
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != 'O') return;
        board[row][col] = '1';
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
    }
};

#include <iostream>
using namespace std;

/*

    Write a program to solve a Sudoku puzzle by filling the empty cells.

    A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    The '.' character indicates empty cells.

    

    Example 1:
    Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
    Explanation: The input board is shown above and the only valid solution is shown below:


    Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit or '.'.
    It is guaranteed that the input board has only one solution.

    [Thought]

    1. 二維 for 循環 
        i --> 代表 row
        j --> 代表 col

    2. 遞歸方式，嘗試 1~9 哪個值比較適合

    3. 本題回朔，返回值不是 void，而是 bool
        --> 因為本題不需要返回多個結果

        [總結]
        1. 搜尋單個樹枝，用 bool
        2. 搜尋整個結果，用 void
            --> Binary Tree，也歸納過
                --> LeetCode 112 Path Sum I


    [Similar Question]
    1. LeetCode 51 Queens
*/

class Solution {
private:
    bool backtracking(vector<vector<char>>& board) {
        // 二維 for 循環：
            // i 為 row
            // i 為 col
        for(int i  = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                // 處理尚未填寫的格子
                if(board[i][j] == '.') {
                    // 填寫 1~9
                    for(char k = '1'; k <= '9'; k++) {
                        // 判斷填入的值，是否合理
                        if(isValid(i, j, k, board)) {
                            // 合理才可以放置
                            board[i][j] = k;
                            if(backtracking(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    // 9 個值都測試都沒過
                    return false;
                }
            }
        }
        // 遍歷完，沒有返回 false，說明找到合適的棋盤位置了
        return true;
    }
    // 判斷機制
    bool isValid(int row,  int col, char val, vector<vector<char>>& board) {
        // 判斷行 row 是否有重複的值
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == val) return false;
        }
        // 判斷列 col 是否有重複的值
        for(int j = 0; j < 9; j++) {
            if(board[j][col] == val) return false;
        }
        // 9 宮格裡面是否有重複
        // row
        int innerRow = (row / 3) * 3;
        // col
        int innerCol = (col / 3) * 3;
        // 利用 二維 for 回圈查找是否有相同的值
        for(int i = innerRow; i < innerRow + 3; i++) {
            for(int j = innerCol; j < innerCol + 3; j++) {
                if(board[i][j] == val) return false;
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main() {
    
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solution;
    solution.solveSudoku(board);

    // 輸出棋盤
    for (const auto& row : board) {
        for (char c : row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
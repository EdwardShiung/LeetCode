#include <iostream>
using namespace std;


/*
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle. 
    You may return the answer in any order.

    Each solution contains a distinct board configuration of the n-queens' placement, 
    where 'Q' and '.' both indicate a queen and an empty space, respectively.

    

    Example 1:

    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

    Example 2:

    Input: n = 1
    Output: [["Q"]]


    [Thought]
    1. n 皇后：當皇后 Q 放入格子中時，每一行、每一列、甚至放入的 45 度角，不能有其他 Q
        - 一開始會覺得很難，是因為太少思考二維以上陣列。
        - 可以先行思考一下，如果是 3 * 3 的情況下，要如何實作出來。
    2. 解決方式:
        
        - Step 01: 參數設定：
                n           : 棋盤大小
                row         : 第幾行
                chessboard  : 棋盤結果
        
        - Step 02: 終止條件：
                row == n
                    - 將 chessboard 放入 results
        
        - Step 03: 單層邏輯
                在裡面判斷 是否合法擺放位置
                    - 用 isValid 去判斷
                        - 同一行(Col) --> 不用判斷
                        - 同一列(Row) --> 要判斷
                        - 45 度角 (左上)
                        - 135 度角 (右上)
*/

class Solution {
private:

    // Create a result
    vector<vector<string>> results;
    
    // Backtracking Method
    void backtracking(int n, int row, vector<string>& chessboard) {
        // 終止條件：
        if(row == n) {
            results.push_back(chessboard);
            return;
        }
        // 單層邏輯：
        for(int col = 0; col < n; col++) {
            if(isValid(row, col, chessboard, n)){
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    // isValid
    bool isValid(int row, int col, vector<string>& chessboard, int n ) {
        // 檢查同一行 --> 不用做
        // --> 因為在單層搜索的過成中，每一層遞歸，只會選擇 for 循環 同一行里的“一個元素”

        // 檢查同一列
        for(int i = 0; i < row; i++) {
            if(chessboard[i][col] == 'Q') return false;
        }

        // 檢查 45 度角
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(chessboard[i][j] == 'Q') return false;
        }

        // 檢查 135 度角
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(chessboard[i][j] == 'Q') return false;
        }
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        // 初始化一個棋盤，並且都先放 ','
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return results;
    }
};


int main() {
    
    int sizeOfBoard = 4;

    Solution solution;

    vector<vector<string>> results = solution.solveNQueens(sizeOfBoard);

    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << endl;;
        }
        cout << endl;
    }
    
    return 0;
}
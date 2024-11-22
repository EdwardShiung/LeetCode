#include <iostream>
using namespace std;


/*

You are given an m x n binary matrix matrix.

You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

Return the maximum number of rows that have all values equal after some number of flips.

 

Example 1:

Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.
Example 2:

Input: matrix = [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.
Example 3:

Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is either 0 or 1.

*/


class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // Using a hashmap to store the key(each row status) and numbers of same status
        // Find the equavelent or the same row
        // Convert the row to the string
        unordered_map<string, int> rowSchema;

        // Using the for-loop
        for(const auto& row: matrix) {
            // Store key 
            string key = "";
            // Using bool to verify the first num is 0 or 1 in each row
            bool flip = row[0] == 1 ? true : false;
            // If the first num is "1" in row, flip it.
            for(int num : row) {
                if(flip){
                    key += '0' + (1 - num);
                }else {
                    key += '0' + num;
                }
            }
            rowSchema[key]++;
        }

        // Get the max number
        int maxCount = 0;
        for(const auto& pair : rowSchema) {
            maxCount = max(maxCount, pair.second);
        } 
        return maxCount;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 1, 0},
        {0, 0, 0}
    };

    int result = solution.maxEqualRowsAfterFlips(matrix);
    cout << result << endl;
}
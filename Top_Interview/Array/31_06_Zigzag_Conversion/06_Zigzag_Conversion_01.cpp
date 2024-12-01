#include<iosteream>
using namespace std;


/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000


*/


class Solution {
    string convert(string s, int numRows) {
        // Basic Limitation
        if(numRows == 1 || numRows >= s.length()) return s;

        // Results
        string results = "";
        // Record the Process By 2D Array
        vector<vector<int>> rows(numRows);

        // Set the beginning index
        int index = 0;
        // Set the direction
        int direct = 1;

        // Record the Proecss by for loop
        for(char c : s) {
            rows[index].push_back(c);
            if(index == 0) {
                direct = 1;
            }
            if(index == numRows - 1) {
                direct = -1;
            }
            index += direct;
        }
        // Re-composition the string
        for(const auto& row: rows) {
            for(char c : row) {
                results += c;
            }
        }
        return results;
    }
};

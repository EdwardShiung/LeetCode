#include <iostream>
#include <vector>
using namespace std;

/*
    [Question]
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
    Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    Example 1:

        Input: digits = "23"
        Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Example 2:

        Input: digits = ""
        Output: []

    Example 3:

        Input: digits = "2"
        Output: ["a","b","c"]
        

    Constraints:

        0 <= digits.length <= 4
        digits[i] is a digit in the range ['2', '9'].

    [Thought]
    1. 本題將電話號碼和英文字串對應，可使用 Array 或 map
    2. 了解為何不需要使用 startIndex，而是使用 index
        - startIndex 使用時機為：在同一個集合下，要調整遍歷初始值
        - 本題 index 為兩個集合，例如：數字 2 和 數字 3 兩集合不同。
    3. 了解終止條件為什麼是 index == digits.size()，而不是 index == digits.size() - 1;
    4. 了解如何將”字串“ 轉換成 “數字” 類型
    5. 本題可得知，深度為輸入字串數量。
*/

class Solution {
private:
    // 電話按鈕上的英文，對應下標
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

public:
    // 單條路線
    string s;
    // Results
    vector<string> results;

    void backtracking(string digits, int index) {
        // 終止條件
        if(index == digits.size()) {
            results.push_back(s);
            return;
        }
        // 單層邏輯
        // 將輸入進來的 digits 轉換成 數字
        int digit = digits[index] - '0';
        // 轉換成數字，可以對應出電話號碼上的英文序列
        string letters = letterMap[digit];
        // for-loop 遍歷
        for(int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtracking(digits, index + 1);
            s.pop_back( );
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return results;
        }
        backtracking(digits, 0);
        return results;
    }
};

int main() {
    string digits = "23";
    Solution solution;
    vector<string> results = solution.letterCombinations(digits);
    for(string s : results) {
        cout << s << " ";
    }
    cout << endl;
}
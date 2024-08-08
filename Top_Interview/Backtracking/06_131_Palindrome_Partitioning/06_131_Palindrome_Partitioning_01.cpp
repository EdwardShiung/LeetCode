#include <iostream>
using namespace std;

/*

    [Question]
    Given a string s, partition s such that every substring of the partition is a palindrome. 
    Return all possible palindrome partitioning of s.

    Example 1:

    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
    Example 2:

    Input: s = "a"
    Output: [["a"]]
    

    Constraints:

    1 <= s.length <= 16
    s contains only lowercase English letters.

    [Thought]
    1. 此問題為切割問題
        - 分辨何為”組合問題“
        - 分辨何為"切割問題"
        - 切割問題與組合問題非常相似！！
    2. 本題思路：
        - Step_01: 參數為：字串陣列、初始位置 
        - Step_02: 本題終止條件，為切割位置大於字串中，最一個下標職位置，即為葉子節點（終止條件）。
        - Step_03: 單層邏輯中，需要判斷，依據切割點，是否有回文
            - 回文邏輯獨立判斷

    [Review]:
    1. 本題可以多思考！！
*/


class Solution {
public:
    // Create a path
    vector<string> path;

    // Create a results
    vector<vector<string>> results;

    // 判斷是否為 Palindrome
    bool isPalindrome(const string& s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtracking(string& s, int startIndex) {
        //  終止條件：切割位置大於字串中，最一個下標職位置，即為葉子節點（終止條件）。
        if(startIndex >= s.size()) {
            results.push_back(path);
            return;
        }
        // for 循環
        for(int i = startIndex; i < s.size(); i++) {
            // 判斷是否回文
            if(isPalindrome(s, startIndex, i)) {
                // 獲取 [startIndex, i] 在 s 中的字串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {
                // 非回文，則跳過
                continue;
            }
            // 尋找 i + 1 的起始位置
            backtracking(s, i + 1);
            // 回朔
            path.pop_back();
        }
    }

    
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return results;
    }

};
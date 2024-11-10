#include <iostream>
using namespace std;


/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) 
is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

*/

class Solution {
public:
    string minWindow(string s, string t) {
            if (s.size() < t.size()) return ""; // 若 s 比 t 短，直接返回空字串

            unordered_map<char, int> tCount, windowCount;
            for (char c : t) {
                tCount[c]++; // 記錄 t 中每個字符的頻率
            }

            int slideBegin = 0, minLength = INT_MAX, start = 0, valid = 0;
            
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if (tCount.count(c)) {
                    windowCount[c]++;
                    if (windowCount[c] == tCount[c]) {
                        valid++; // 當字符頻率達到 t 中所需時，增加 valid
                    }
                }

                // 當窗口包含 t 的所有字符時，開始嘗試收縮窗口
                while (valid == tCount.size()) {
                    if (i - slideBegin + 1 < minLength) {
                        minLength = i - slideBegin + 1;
                        start = slideBegin;
                    }
                    
                    // 移動左邊界，縮小窗口
                    char leftChar = s[slideBegin];
                    slideBegin++;
                    if (tCount.count(leftChar)) {
                        if (windowCount[leftChar] == tCount[leftChar]) {
                            valid--;
                        }
                        windowCount[leftChar]--;
                    }
                }
            }

        // 返回最小窗口子字串，若未找到則返回空字串
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};
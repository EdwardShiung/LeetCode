#include <iostream>
using namespace std;

/*

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

[Thought]:
    1. Method_01: 造輪子！
        - ASCII 
            - Lowercase: 97 - 122
            - Uppercase: 65 - 90

        - C++ 中，大小寫字母轉換
            例如 小寫 a 在  ASCII 中，是 97
            -->  要轉換成大寫:
            錯誤：a - 22
            正確：a - ('a' - 'A')

*/


class Solution {
public:
    bool isPalindrome(string s) {
        // Basic Limitation
        if(s.length() <= 1) return true;
        // Re-organize the string
        string res = "";
        // Re-organize the string (remove the empty space)
        for(int i = 0; i < s.length(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                // Convert Uppercase to Lowercase
                if(s[i] >= 'A' && s[i] <= 'Z') {
                    // res.push_back(s[i] + 22);
                    res.push_back(s[i] + ('a' - 'A'));
                }else {
                    res.push_back(s[i]);
                }
            }
        }

        // Using two pointer
        // left
        int left = 0;
        // right
        int right = res.length() - 1;

        // Using while-loop to compare
        while(left < right) {
            if(res[left] != res[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
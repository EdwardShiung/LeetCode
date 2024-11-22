#include <iostream>
using namespace std;
/*


Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // To store and calculate the number of character
        unordered_map<char, int> charSchema;
        // set LeftPointer (slow)
        int left = 0;
        // set result length
        int maxLength = 0;
        
        int temp = 0;
        // Sliding window
        for(int i = 0; i < s.length(); i++) {
            charSchema[s[i]]++;
            temp++;
             while(charSchema[s[i]] > 1) {
                charSchema[s[left]]--;
                left++;
                temp = i - left + 1;
             }
             maxLength = max(maxLength, temp);
        }
        return maxLength;
    }
};

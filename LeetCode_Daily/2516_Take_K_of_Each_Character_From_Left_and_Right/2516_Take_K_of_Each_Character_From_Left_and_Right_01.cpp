#include <iostream>
using namespace std;

/*
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. 
Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, 
or return -1 if it is not possible to take k of each character.


Example 1:

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. 
You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. 
You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
Example 2:

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
 

Constraints:

1 <= s.length <= 105
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length

*/

class Solution {
public:
    int takeCharacters(string s, int k) {

        // Using unordered_map to store character and count
        unordered_map<char, int> charSchema;

        // 1st Approach: Record the Char and Count the number of each char
        // for(int i = 0; i < s.length(); i++) {
        //     charSchema[s[i]]++;
        // }

        // 2nd Approach: 
        for(char c : s) {
            charSchema[c]++;
        }

        // Edge cases
        if(charSchema['a'] < k || charSchema['b'] < k || charSchema['c'] < k) {
            return - 1;
        }

        // Calculate the length of string s (Total length subtract middle part) 
        // --> which means that we need to find the maximum string length in the middle.
        int stringLength = s.length();
        int maxLength = 0;
        // Using slowPointer for sliding window
        int slowPointer = 0;

        // Sliding Window
            // Calculating the maximum substring that not covered a, b, and c at least number of k
        for(int i = 0; i < s.length(); i++) {
            
            charSchema[s[i]]--;

            // 1st Approach: Check if the current window is valid by ensuring each character count is < k
            // while (charSchema['a'] < k || charSchema['b'] < k || charSchema['c'] < k) {
            //     charSchema[s[slowPointer]]++;
            //     slowPointer++;
            // }

            // 2nd Approach: Check if the current window is valid by ensuring each character count is < k
            while(charSchema[s[i]] < k) {
                charSchema[s[slowPointer]]++;
                slowPointer++;
            }

            // Update the maximum length of middle string
            maxLength = max(maxLength, i - slowPointer + 1);
        }

        // return result
        return stringLength - maxLength;
    }
};
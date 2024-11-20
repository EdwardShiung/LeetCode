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


    [Thought]:
    Using the vector to store the information 
    1. Compared to the file_01, we use the index to stand for a, b, and c.
        -> character of a is the ASCII of 97, b is 98, and c is 99
        -> By subtracting the character of a, we can get the index of 0, 1, and 2, which stand for a, b, and c.

    2. 比較 vector 和 unordered_map 差異：
    - vector: 當你只需要存儲有限種類的字符（例如 'a', 'b', 'c'，總共三個），vector 是一個簡單且輕量的選擇，
        因為你可以輕鬆地將字符轉換成索引，並且不需要哈希結構的額外管理。

    - unordered_map: 適合存儲大量不規則鍵值對的場景，但由於哈希函數計算和處理哈希衝突的成本，
        對於這種簡單、固定大小的用例，unordered_map 並不是最佳選擇。

*/

class Solution {
public:
    int takeCharacters(string s, int k) {
        
        // Using vector to store count
        // Set the default count for each character with 0
        vector<int> charSchema(3, 0);

        // Calculate the number of a, b, and c
        for(char character : s) charSchema[character - 'a']++;

        // Edge cases
        for(int i = 0; i < charSchema.size(); i++) {
            if((charSchema[i] -= k) < 0) return -1;
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
            
            charSchema[s[i] - 'a']--;

            // 2nd Approach: Check if the current window is valid by ensuring each character count is < k
            while(slowPointer <= i && charSchema[s[i] - 'a'] < 0) {
                charSchema[s[slowPointer] - 'a']++;
                slowPointer++;
            }

            // Update the maximum length of middle string
            maxLength = max(maxLength, i - slowPointer + 1);
        }
        // return result
        return stringLength - maxLength;
    }
};
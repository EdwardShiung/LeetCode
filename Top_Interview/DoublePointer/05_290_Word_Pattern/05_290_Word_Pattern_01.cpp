#include <iostream>
using namespace std;

/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false

 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

    [Thought]:
    1. You have to familiar with hashmap.

*/


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        // Using a unordermap to record the pattern (char -> string)
        unordered_map<char, string> record;
        // Using a unordermap to record the pattern (string -> char)
        unordered_map<string, char> reverseRecord;

        // string temp
        string temp = "";

        //slow pointer
        int slow = 0;

        for(int i = 0; i <= s.length(); i++) {
            if(s[i] == ' ' || i == s.length()){

                // Situation_01: slow > pattern.length()
                if(slow > pattern.length() - 1) {
                    return false;
                }

                // Verify the key to string
                if(record.count(pattern[slow])) {
                    if(record[pattern[slow]] != temp) {
                        return false;
                    }
                }else {
                    record[pattern[slow]] = temp;
                }
                // Verify the string to key
                if(reverseRecord.count(temp)) {
                    if(reverseRecord[temp] != pattern[slow]) {
                        return false;
                    }
                }else {
                    reverseRecord[temp] = pattern[slow];
                }
                slow++;
                temp = "";
            }else {
                temp.push_back(s[i]);
            }
        }

        // Situation_02: Pattern still have but s is already verifed completely.
        if(slow < pattern.length()) {
            return false;
        }
        return true;
    }
};
#include <iostream>
using namespace std;

/*
Given two strings s and t, return true if they are equal 
when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 
Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?

*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slowIndex = 0;

        // s
        for(int fastIndex = 0; fastIndex < s.size(); fastIndex++) {
            if(s[fastIndex] == '#'){
                if(slowIndex > 0) slowIndex--;
            }else{
                s[slowIndex] = s[fastIndex];
                slowIndex++;
            }
        }
        s.resize(slowIndex);

        slowIndex = 0;

        // t
        for(int fastIndex = 0; fastIndex < t.size(); fastIndex++) {
            if(t[fastIndex] == '#'){
                if(slowIndex > 0) slowIndex--;
            }else{
                t[slowIndex] = t[fastIndex];
                slowIndex++;
            }
        }
        t.resize(slowIndex);
        return s == t;
    }
};


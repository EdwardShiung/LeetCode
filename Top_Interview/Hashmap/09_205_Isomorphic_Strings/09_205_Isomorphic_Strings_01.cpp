#include <iostream>
using namespace std;


/*

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

    [Thought]:
    1. Understand about the hash map method, such as find, count, and end.


*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> charIndexS;
        unordered_map<char, int> charIndexT;

        for (int i = 0; i < s.length(); i++) {

            //  Solution_01
            // if (charIndexS.find(s[i]) == charIndexS.end()) {
            //     charIndexS[s[i]] = i;
            // }

            // if (charIndexT.find(t[i]) == charIndexT.end()) {
            //     charIndexT[t[i]] = i;
            // }

            // Solution_02
            if (charIndexS.count(s[i]) == 0) {
                charIndexS[s[i]] = i;
            }

            if (charIndexT.count(t[i]) == 0) {
                charIndexT[t[i]] = i;
            }

            if (charIndexS[s[i]] != charIndexT[t[i]]) {
                return false;
            }
        }
        return true;        
    }
};
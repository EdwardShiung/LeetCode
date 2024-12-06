#include <iostream>
using namespace std;

/*
Given an array of strings strs, group the 
anagrams
 together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

    [Thought]:
    1. Understand how to generate the unique key by sorting the characters in each word, 
        so that we can use that to be a unique key and store the value
    2. unordered_map--> key and value could be any type, include the vector

*/


class Solution {
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Using hashmap to record the words
        unordered_map<string, vector<string>> records;

        // Using for-loop to record each words
        for(string s : strs) {
            // store the temp string
            string tempString = s;
            // Sorted the character in each word
            sort(tempString.begin(), tempString.end());
            // After sorting the characters, we can use re-composized words to be a key.
            records[tempString].push_back(s);
        }

        // Using a results vector to retrive each value
        vector<vector<string>> results;
        for(auto s : records) {
            results.push_back(s.second);
        }

        // Return a results
        return results;
    }
}
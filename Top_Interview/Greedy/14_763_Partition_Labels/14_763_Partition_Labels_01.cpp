#include <iostream>
using namespace std;


/*
You are given a string s. 
We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, 
the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/



class Solution {
public:
    vector<int> partitionLables(string s) {
        // Record the number of english character
        // 0-25 stand for a-z
        int hashtable[26] = {0};
        // Using for-loop to detect the string s
        for(int i = 0; i < s.size(); i++) {
            hashtable[s[i] - 'a'] = i;
        }
        // After recording the english character, we can start to get the results;
        vector<int> result;
        // left
        int left = 0;
        // right
        int right = 0;
        // Using loop to separate the string s
        for(int i = 0; i < s.size(); i++) {
            // set the right flag
            right = max(right, hashtable[s[i] - 'a']);
            // if right flag == i, it means that it could separate the string s
            if(i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

int main(){
    char a = 'a';
    char z = 'z';
    printf("a: %d\n", a);
    printf("z: %d\n", z);
}
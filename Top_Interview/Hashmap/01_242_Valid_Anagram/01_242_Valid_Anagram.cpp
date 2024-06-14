#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            
            // Record 26 English character
            int record[26] = {0};
            
            // Using ASCII to record the time
            /*
              Record which character in the string s(Input).
              If the character show up, add 1, which means that to cout the times by each time.
             */ 
            for(int i = 0; i < s.size(); i++) {
                int val = s[i] - 'a';
                record[val]++;
            }

            // Compared the input t by the previous Hashmap.
            /*
                If the string t have some value in the hashmap, 
                it will deduct the value by 1.
            */
           for(int i = 0; i < t.size(); i++) {
                int val = t[i] - 'a';
                record[val]--;
           }

           //   Check the Hashmap
           /*
                If the Hashmap still have number 1, 
                it means that string s and string t are not valid anagram.
           */
            for(int i = 0; i < 26; i++) {
                if(record[i] != 0) {
                    cout << false << endl;
                    return false;
                }
            }

            /*
                If all the value in the Hashmap are 0,
                it means that string s and string t are valid anagram.
            */
           cout << true << endl;
           return true;
        
        }
};

/*
    The first thought is using the array to be the hashmap, which means that we create the 26 elements
    Time Complexity O(n);
    Space Complexity O(1)
*/

int main() {
    string s = "anagram";
    string t = "nagaramt";

    Solution sol;
    sol.isAnagram(s,t);
    return 0;
}
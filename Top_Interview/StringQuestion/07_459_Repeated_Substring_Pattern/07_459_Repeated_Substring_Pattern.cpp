#include <iostream>
using namespace std;


/*

Ex_01:
    s = "abab"

    --> s + s
    --> abab + abab = abababab
    --> delete the first & last characters
        --> it's because "abab" is covered by "bababa".
        --> true 
    
Ex_02:

    s = "aba"
    --> s + s 
    --> aba + aba = abaaba
    --> delete the first & last characters
    --> baab
        --> "aba" is not covered by "baab".
        --> false

*/



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        // Add a newString
        string newString = s + s;

        // Set a flag
        int flag = 0;

        for(int i = 1; i < newString.size() - s.size(); i++) {
            if(newString[i] == s[0]){
                int j = 0;
                while(j < s.size() && newString[i + j] == s[j]) {
                    j++;
                }
                if(j == s.size()) return true;
            }
        }

        return false;
    }
};


int main() {
    Solution solution;
    string s = "aba";
    bool result = solution.repeatedSubstringPattern(s);
    cout << result << " ";
    cout << endl;
}

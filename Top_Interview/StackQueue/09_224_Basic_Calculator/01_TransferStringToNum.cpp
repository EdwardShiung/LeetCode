#include <iostream>
using namespace std;


/*
By Solving the problem, we have to understand how to transfer the string to number.
So, we have to understand each of process.
[1st Step]:
    Transfer the string written by string not integer.
    1.  Using the char - '0'. 

[2nd Step]:
    1. Understand the problem:
        -   '+' is not used as a unary operation 
            (i.e., "+1" and "+(2 + 3)" is invalid).
        
        -   '-' could be used as a unary operation 
            (i.e., "-1" and "-(2 + 3)" is valid)

[WARNING]:
    1. Don't use the syntax below:
        string s = "1";
        string transferString = int(s);
        --> By this way, it will get the result by ASCII.
                --> That's why get the wrong answer that is 49.
    2. ASCII：
    '0' stand for 48. 
    If we want to get the number from string, using the way below.
    '1' - '0' = 49 - 48 = 1
    '2' - '0' = 50 - 48 = 2
    '3' - '0' = 51 - 48 = 3
*/

class Solution {
public:
    // Right Approach (O)
    int transferStringToNum(string s) {
        int sign = 1;
        int result = 0;
        // Using the i to iterate the string
        int i = 0;
        while(i < s.size()) {
            if(isdigit(s[i])){
                // Key Point to transfer.
                int num = s[i] - '0';
                while(i + 1 < s.size() && isdigit(s[i + 1])) {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                result += num * sign;
            }else if(s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        return result;
    }
    
    // Wrong Approach (X)
    // int transferStringToNum(string s) {
    //     int sign = 1;
    //     int result = 0;
    //     int i = 0;
    //     while(i < s.size()) {
    //         if(isdigit(s[i])) {
    //             int num = int(s[i]);
    //             while(i + 1 < s.size() && isdigit(s[i])) {
    //                 num = num * 10 + int(s[i]);
    //                 i++;
    //             }
    //             result = num * sign;
    //         }else if(s[i] == '-') {
    //             sign = -1;
    //         }
    //         i++;
    //     }
    //     return result;
    // }
};

int main() {
    Solution sol;
    string test = "1";
    int res = sol.transferStringToNum(test);
    cout << res << endl;
}
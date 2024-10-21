#include <iostream>
using namespace std;

/*
An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.

Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

 

Example 1:

Input: n = 10
Output: 9
Example 2:

Input: n = 1234
Output: 1234
Example 3:

Input: n = 332
Output: 299
 

Constraints:

0 <= n <= 109

[Thought]:
    1. Method_01: Using the brutal force method to get the number.
    2. Method_02: Using the Greedy to solve the problem.
        - We have to find out the partial optimization and to infer the all results.

*/

class Solution {


public:
    int monotoneIncreasingDigits(int n) {
        // Step_01: Covert number to string
        string convertNS = to_string(n);
        // printf("%s\n", convertNS.c_str());
        // set a flag (We need a flag to understand which index should put number 9)
        int flag = convertNS.size();
        for(int i = convertNS.size() - 1; i > 0; i--) {
            if(convertNS[i - 1]> convertNS[i]) {
                flag = i;
                convertNS[i - 1]--; 
            }
        }

        // Using a loop to put number 9 after the flag index
        for(int i = flag; i < convertNS.size(); i++) {
            convertNS[i] = '9';
        }
        printf("%s\n", convertNS.c_str());
        return stoi(convertNS);
    }
};

int main() {
    Solution solution;
    solution.monotoneIncreasingDigits(332);
}
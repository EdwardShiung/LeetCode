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
private:
    // The function for findInteger is 
    bool checkNum(int num) {
        int max = 10;
        while(num) {
            int eachNum = num % 10;
            if(max >= eachNum) {
                max = eachNum;
            }else{
                return false;
            }
            num = num / 10;
        }
        return true;
    }

public:
    int monotoneIncreasingDigits(int n) {
        for(int i = n; i > 0; i--) {
            if(checkNum(i)) {
                printf("i: %d\n", i);
                return i;
            }
        }
        // In the situation, you have to give a zero value.
        return 0;    
    }
};

int main() {
    Solution solution;
    solution.monotoneIncreasingDigits(332);
}
#include <iostream>
using namespace std;

/*

The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum of the two preceding ones, 
starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Constraints:

0 <= n <= 30

[Thought]:
    1. Using the recursive method to solve the problem. File_01.
    2. Using the DP method to solve the problem. File_02.

    - DP 5 Steps:
    Step_01: 確定dp[i]含義 (Define the dp[i])
        - In this case, the dp[i] : 第 i 個 Fibonacci 數
    Step_02: 遞歸函式 (Recursive Function)
        - dp[i] = dp[i - 1] + dp[i - 2]
    Step_03: 初始化值 (Initialize)
        - dp[0] = 1, dp[1] = 1
    Step_04: 確定 loop 順序
    Step_05: print 出結果驗證

*/

class Solution {
public:
    int fib(int n) {
        // Don't forget the limitation
        if(n <= 1) return n;

        //Step_01: Define the dp[i]
        //Step_02: Initialize the dp
        vector<int> dp(n + 1);
        //Step_03: Initialize the value
        dp[0] = 0;
        dp[1] = 1;
        //Step_04:
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};


int main() {
    int n = 3;

    Solution solution;
    int results = solution.fib(n);
    // Step_05: Verify (print the result)
    printf("%d", results);
}
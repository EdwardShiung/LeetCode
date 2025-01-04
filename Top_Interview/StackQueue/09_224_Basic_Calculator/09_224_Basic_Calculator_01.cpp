#include <iostream>
#include <stack>
using namespace std;


/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*/


class Solution {
public:
    int calculate(string s) {
        // Using the Stack to assist the calculate
        stack<int> stk;
        int sign = 1;
        int result = 0;
        int i = 0;

        // Using the while loop to iterate the string
        while(i < s.size()) {
            if(isdigit(s[i])) {
                int num = s[i] - '0';
                while(i + 1 < s.size() && isdigit(s[i + 1])) {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                result += num * sign;
            }else if(s[i] == '+') {
                sign = 1;
            }else if(s[i] == '-') {
                sign = -1;
            // Deal with the parenthesis situation
            }else if(s[i] == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            }else if(s[i] == ')') {
                // 棧頂是符號
                // 這個動作是，最裡面的括弧，已經完成了相加
                // 將外層的正負號跳出
                // 最後再加上上一層的內容
                result = result * stk.top();
                // 符號移除
                stk.pop();
                // 再拿出數字
                result += stk.top();
                // 數字移除
                stk.pop();
            }
            i++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "1 + 1";
    int res = sol.calculate(s);
    printf("%d", res);
}
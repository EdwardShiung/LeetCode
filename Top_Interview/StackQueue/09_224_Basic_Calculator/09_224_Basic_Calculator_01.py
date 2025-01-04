'''
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

'''


class Solution:
    def calculate(self, s: str) -> int:
        # Using a Stack to assist the calculator
        stack = []
        # Using a Sign to note the operation
        # Define sign 1 == '+'
        # Define sign -1 == '-' 
        sign = 1
        result = 0
        i = 0

        # Using for-loop to travel the string
        while i < len(s):
            character = s[i]
            if character.isdigit():
                num = int(s[i])
                while i + 1 < len(s) and s[i + 1].isdigit():
                    num = num * 10 + int(s[i + 1])
                    i += 1
                result += num * sign
            elif character == '+':
                sign = 1
            elif character == '-':
                sign = -1
            elif character == '(':
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1
            elif character == ')':
                result = result * stack.pop() + stack.pop()
            i += 1
            
        return result

test = "123"
res = Solution().calculate(test)
print(res)

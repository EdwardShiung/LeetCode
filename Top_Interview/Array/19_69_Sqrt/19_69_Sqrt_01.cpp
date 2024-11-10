#include <iostream>
using namespace std;

/*

Given a non-negative integer x, 
return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1


*/


class Solution {
public:
    int mySqrt(int x) {

        if(x == 0 || x == 1) return x;
        int left = 0;
        int right = x;
        int results = 0;

        while(left <= right) {
            int middle = left + (right - left) / 2;

            if(middle > x / middle) {
                right = middle - 1;
            }else{
                // middle could equal to results or less than results
                results = middle;
                left = middle + 1;
            }
        }
        return results;
    }
};

int main() {
    Solution sol;

    int result = sol.mySqrt(0);

    cout << result << endl;

    return 0;
}
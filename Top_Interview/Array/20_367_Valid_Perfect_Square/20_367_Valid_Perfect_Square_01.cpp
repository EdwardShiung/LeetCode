#include <iostream>
using namespace std;


/*
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. 
In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
 

Constraints:

1 <= num <= 231 - 1

*/


class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 1) return false;
        int left = 1;
        int right = num;

        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(middle > num / middle) {
                right = middle - 1;
                continue;
            }
            if(middle < num / middle) {
                left = middle + 1;
                continue;
            }else{
                return num % middle == 0;
            }
        }
        return false;
    } 
};


// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         if(num < 1) return false;
//         int left = 1;
//         int right = num;

//         while(left <= right) {
//             int middle = left + (right - left) / 2;
//             if(middle > num / middle) {
//                 right = middle - 1;
//             } else if(middle < num / middle) {
//                 left = middle + 1;
//             } else {
//                 return num % middle == 0;
//             }
//         }
//         return false;
//     }
// };


int main() {
    int num = 5;
    Solution sol;

    bool result = sol.isPerfectSquare(num);
    cout << result << endl;
    return 0;
}

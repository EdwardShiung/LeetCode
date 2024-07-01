#include <iostream>
using namespace std;


/*
Right Rotation of a String

The right rotation operation of a string involves moving a certain number of characters from the end of the string to the beginning. 

Given a string s and a positive integer k, write a function that moves the last k characters of the string to the front, thereby performing the right rotation operation on the string.

For example, given the input string "abcdefg" and the integer 2, the function should convert it to "fgabcde".

Input: The input consists of two lines. The first line contains a positive integer k, representing the number of positions to rotate to the right. The second line contains the string s, representing the string to be rotated.

Output: The output consists of a single line, which is the string after performing the right rotation operation.
*/


class Solution {
public:
    void reverse(string& s, int start, int end) {
        while(start < end) {
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;

            start++;
            end--;
        }
    }

    string rightRotation(string s, int length) {
        // Step_01: Reverse all of the elements in the string.
        reverse(s, 0, s.size() - 1);
        // Step_02: Reverse first part 0-index
        reverse(s, 0, length - 1);
        // Step_03: Reverse second part index-end
        reverse(s, length, s.size() - 1);

        return s;
    }
};

int main(){
    
    Solution solution;

    string s;
    int n;
    cout << "Please input a string:" << endl;
    cin >> s;
    cout << "Please input the length of rotation" << endl;
    cin >> n;

    s = solution.rightRotation(s, n);

    cout << s << endl;
}
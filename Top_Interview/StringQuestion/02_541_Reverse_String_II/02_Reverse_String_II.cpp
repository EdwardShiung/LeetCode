#include <iostream>
using namespace std;


/*

    Question:
    Given a string s and an integer k, 
    reverse the first k characters for every 2k characters counting from the start of the string.
    
    If there are fewer than k characters left, reverse all of them. 
    If there are less than 2k but greater than or equal to k characters,
    then reverse the first k characters and leave the other as original.

    Ex: 0123456
        abcdefg     k = 2
           ^      
    --> bacdfeg

    //思路：
    1. 一次走 2k 步
    2. 利用 reverse 去翻轉 
       翻轉 i 到 i + k
       ps. c++ 提供的 reverse 函數為左閉右開

    Review:
    1. 左閉右閉、左閉右開 關念
    2. continue 思路
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
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i +=(2 * k)) {
            if(i + k <= s.size()) {
                // (區間要注意)
                reverse(s, i, i + k - 1);
                // 都優先處裡 前 2k 中的 k 個（處理完，跳到下一輪，不執行尾部翻轉）
                continue;
            }
            //尾部翻轉 (區間要注意)
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};


int main() {
    string s = "abcdefg";

    Solution solution;
    string results = solution.reverseStr(s,2);

    for(int i = 0; i < results.size(); i++) {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}
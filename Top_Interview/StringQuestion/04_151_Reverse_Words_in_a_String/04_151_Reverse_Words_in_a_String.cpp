#include <iostream>
using namespace std;


/*

    [思路]：
    1. remove extra space first
        --> The logic is the same with Leetcode 27 Remove Element
            --> Using double pointers could reduce the time complexity to O(n)
    2. reverse all of the string s
    3. after reverse all of the string s, reverse each word in the string

*/


class Solution {
public:

    void reverse(string& s, int start, int end) {
        while(start < end){
            char temp = s[end];
            s[end] = s[start];
            s[start] = temp;
            start++;
            end--;
        }
    }


    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }


    // void removeExtraSpaces(string s) {
    //     // Using slow pointer to identify the extra space
    //     int slowPointer = 0;
    //     for(int fastPointer = 0; fastPointer < s.size(); fastPointer++) {
    //         // 遇到非空，則處理 (因為有可能遇到這種例子 ex: [    Hello world])
    //         if(s[fastPointer] != ' '){
    //             if(slowPointer != 0){
    //                 s[slowPointer] = ' ';
    //                 slowPointer++;
    //             }
    //             while(fastPointer < s.size() && s[fastPointer] != ' '){
    //                 s[slowPointer] = s[fastPointer];
    //                 fastPointer++;
    //                 slowPointer++;
    //             }
    //         }
    //     }
    //     s.resize(slowPointer);
    // };

    string reverseWords(string s) {
        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }


    // string reverseWords(string s) {
    //     // 處理多的空格
    //     removeExtraSpaces(s);
    //     // 處理翻轉
    //     reverse(s, 0, s.size() - 1);
    //     // 需要記錄每個單詞的始末
    //     int start = 0;
    //     for(int i = 0; i < s.size(); i++) {
    //         if( i == s.size() || s[i] == ' ') {
    //             reverse(s, start, i - 1);
    //             start = i + 1;
    //         }
    //     }
    //     return s;
    // };
};

int main() {
    Solution solution;
    string resultsWordsInString = solution.reverseWords("the sky is blue");
    cout << resultsWordsInString << " ";
    cout << endl;

    return 0;
}
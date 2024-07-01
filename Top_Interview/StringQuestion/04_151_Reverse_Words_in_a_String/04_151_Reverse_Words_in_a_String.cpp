#include <iostream>
#include <string>
using namespace std;


/*

    [思路]：
    1. remove extra space first
        --> The logic is the same with Leetcode 27 Remove Element
            --> Using double pointers could reduce the time complexity to O(n).
        --> Using the pointer, which means that it could keep the Space Complexity to O(1).
    2. reverse whole string s
        --> Using the pointer, which means that it could keep the Space Complexity to O(1).
        [Results]:
            Ex: the sky is blue.
            --> eulb si yks eht.
    3. after reverse all of the string s, reverse each word in the string.

*/


class Solution {
public:

    // Reverse Function: Made by Me
    // [Method_01]:
    // void reverse(string& s, int start, int end) {
    //     while(start < end){
    //         char temp = s[end];
    //         s[end] = s[start];
    //         s[start] = temp;
    //         start++;
    //         end--;
    //     }
    // }

    // Reverse Function: Using swap method
    // [Method_02]:
    void reverse(string& s, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
    //     int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
    //     for (int i = 0; i < s.size(); ++i) { //
    //         if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
    //             if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
    //             while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
    //                 s[slow++] = s[i++];
    //             }
    //         }
    //     }
    //     s.resize(slow); //slow的大小即为去除多余空格后的大小。
    // }


    void removeExtraSpaces(string& s) {
        // Slow Pointer:
        // 1. Using slow pointer to update the character's position.
        // 2. Using slow pointer to update where is the end of the word!!
            // --> If the end of the word, slow pointer will leave one space and update itself position to keep going update the new character.
        int slowPointer = 0;
        // Faster Pointer:
        // Using fast pointer to search the character.
        for(int fastPointer = 0; fastPointer < s.size(); fastPointer++) {
            if(s[fastPointer] != ' '){
                // Once the end of word, it will generate one space and update itself position.
                if(slowPointer != 0){
                    s[slowPointer] = ' ';
                    slowPointer++;
                }
                while(fastPointer < s.size() && s[fastPointer] != ' '){
                    s[slowPointer] = s[fastPointer];
                    fastPointer++;
                    slowPointer++;
                }
            }
        }
        // slow 最後移動的值，即為去除多餘空格的大小
        s.resize(slowPointer);
    };

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
    string randomString = "the sky is blue";
    solution.reverse(randomString, 0, randomString.size() - 1);
    cout << randomString << " ";
    cout << endl;


    string resultsWordsInString = solution.reverseWords("the sky is blue");
    cout << resultsWordsInString << " ";
    cout << endl;

    return 0;
}
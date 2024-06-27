#include <iostream>
#include <string>
using namespace std;

/*
Given a string s, which contains lowercase letters and numeric characters, 
please write a function that keeps the letter characters unchanged and replaces each numeric character with "number".

For example, for the input string "a1b2c3", the function should convert it to "anumberbnumbercnumber".

For the input string "a5b", the function should convert it to "anumberb".

Input: a string s, where s contains only lowercase letters and numeric characters.

Output: print a new string where each numeric character is replaced with "number".

Sample input: a1b2c3

Sample output: anumberbnumbercnumber

Data range: 1 <= s.length < 10000.


    [題型]: 字串、陣列填充類問題
    1. 從頭開始：Time Complexity O(n^2)
    2. 從尾開始：Time Complexity O(n)

    [思路]：
    1. 先計算出輸入字串中，數字有幾個數
    2. 擴容！！本題追求快速，使用 resize() 函數
    3. 由尾到頭，依序替換
        - 遇到數字則替換
        - 沒有遇到則將英文字母放置後

    [學習]：
    1. resize 函數
*/


class Solution {
public:
    // Get Random String
    string getRandomString() {
        cout << "Please input an Random String:" << endl;
        string randomString;
        cin >> randomString;
        cout << "Your input String is:\n" << randomString << endl;
        return randomString;
    };

    // Calculate the integers from the random string
    int calculateNum(string randomString) {
        int count = 0;
        for(int i = 0; i < randomString.size(); i++) {
            if(randomString[i] >= '0' && randomString[i] <= '9') {
                count++;
            }
        }
        cout << count << " integer(s)";
        cout << endl;
        return count;
    };

    // Transfer Integers to "number" word
    string transferToNumberWord(string randomString, int count) {
        // Record the old index of the end of randomString
        int oldIndex = randomString.size() - 1;

        // Extending the size of random string.
        // Because "number" has 6 character, and each number replaces with 6 character,
        // it will increase 5 length in one string.
        // Using "resize method" to extend the size of random string
        randomString.resize(randomString.size() + (count * 5)); 

        // New Index of the end of random string
        int newIndex = randomString.size() - 1;

        // Using while-loop to replace the number word with integer
        while(oldIndex >= 0) {
            
            if(randomString[oldIndex] >= '0' && randomString[oldIndex] <= '9') {
                randomString[newIndex--] = 'r';
                randomString[newIndex--] = 'e';
                randomString[newIndex--] = 'b';
                randomString[newIndex--] = 'm';
                randomString[newIndex--] = 'u';
                randomString[newIndex--] = 'n';
            }else{
                randomString[newIndex] = randomString[oldIndex];
                newIndex--;
            }

            oldIndex--;
        }
        cout << "New String: " << randomString << endl;
        return randomString;
    };
};

int main() {
    // Initialize Solution Class
    Solution solution;
    string randomString = solution.getRandomString();

    // Calculate the number of integers
    int count = solution.calculateNum(randomString);

    // Transfer the Integer to "number" word
    string resultString = solution.transferToNumberWord(randomString, count);

    return 0;
}
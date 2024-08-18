#include <iostream>
using namespace std;
/*
    Given a string s, partition s such that every 
    substring of the partition is a palindrome. 
    Return all possible palindrome partitioning of s.

    

    Example 1:

    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
    Example 2:

    Input: s = "a"
    Output: [["a"]]
    

    Constraints:

    1 <= s.length <= 16
    s contains only lowercase English letters.


    [Review]:
    1. 本題可以多思考！！
        - 尤其邊界和索引關係

    [Similar Question]
    1. LeetCode 93


*/
class Solution {
public:
    // Create a path 
    vector<string> path;

    // Create a result
    vector<vector<string>> results;

    // Backtracking
        // 參數設置及回傳值：
    void backtracking(string& s, int startIndex) {
        // 終止條件：
        if(startIndex == s.size()) {
            results.push_back(path);
            return;
        }
        // 層層遞歸：
        for(int i = startIndex; i < s.size(); i++) {
            // 每一層，切割處（可分為左右兩邊），是否為回文
                // 如果是回文，放入 path
                    // 判斷字串的位置：
                        // 1. startIndex 起始位置
                        // 2. end 為 最右邊位置
            if(isPalindrome(s, startIndex, i)) {
                // 使用 substr 擷取目前的字串
                    // 參數：
                        // 1st: starting position
                        // 2nd: length of string
                string subString = s.substr(startIndex, i - startIndex + 1);
                path.push_back(subString);
            }else{
                // 非回文的話，就繼續下一個循環
                continue;
            }
            // 繼續下一個循環，因此： Backtracking 使用
            backtracking(s, i + 1);
            // 回朔：
            path.pop_back();
        }
    }
    
    bool isPalindrome(string& s, int start, int end) {
        for(int i  = start, j = end; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return results;
    }
};

int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string>> results = solution.partition(s);


    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
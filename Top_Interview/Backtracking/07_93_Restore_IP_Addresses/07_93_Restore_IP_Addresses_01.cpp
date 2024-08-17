#include <iostream>
using namespace std;

/*
    [Question]
    A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

    For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
    Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. 
    You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

    

    Example 1:

    Input: s = "25525511135"
    Output: ["255.255.11.135","255.255.111.35"]
    Example 2:dc

    Input: s = "0000"
    Output: ["0.0.0.0"]
    Example 3:

    Input: s = "101023"
    Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
    

    Constraints:

    1 <= s.length <= 20
    s consists of digits only.


    [Thought]:
    1. 本題為“切割問題”

    [Similar Question]
    1. LeetCode 131



*/
class Solution {

public:

    // Create a path
    vector<string> path;

    // Create a results array
    vector<string> results;

    // backtracking 找尋切割
    void backtracking(string& s, int startIndex, int pointSum) {
        // pointSum：因為切割問題，可以看成一棵樹，這棵樹，從根部為第 0 層，最多會到第 3 層。
            // 如果 ip 字段合理，就會加入到 results 中。
        if(pointSum == 3) {
            if(isValid(s, startIndex, s.size() - 1)) {
                results.push_back(s);
            }
            return;
        }

        // 個別段 IP 處理 （樹的每一層處理）
        for(int i = startIndex; i < s.size(); i++) {
            if(isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointSum ++;
                //  i + 2 原因：有加上 . 
                backtracking(s, i + 2, pointSum);
                s.erase(s.begin() + i + 1);
                pointSum --;
            }
        }
    }

    // isValid 判斷是否為合理的 IP 
    bool isValid(const string& s, int start, int end) {
        // 條件判斷:    限制不可 start > end
        if(start > end) return false;
        // 條件判斷：   每個字段開頭，start != end，則 start 不可以為 0
        if(s[start] == '0' && start != end) return false;

        // 條件判斷：   每個字段中:
                        //   1. 不可為非正整數
                        //   2. 須小於 255
        
        int num = 0;
        for(int i = start; i <= end; i++) {
            // 條件 1:
            if(s[i] > '9' || s[i] < '0')  return false;
            // 條件 2:
            /*
            ex: 168
            首先 num 是 1， 然後變成 16，最後變成 168。由於 168 <= 255，所以這個子串是合法的 IP 地址段。

            ps:
                (s[i] - '0')
                這個部分將字串，轉換成數值
            
            */
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return results;
    }
};


int main() {
    
    string s = "25525511135";

    Solution solution;

    vector<string> results = solution.restoreIpAddresses(s);

    for(string s: results) {
        cout << s << endl;
    }
    return 0;
}
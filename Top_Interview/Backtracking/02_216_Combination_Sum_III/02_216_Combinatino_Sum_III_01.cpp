#include <iostream>
using namespace std;
/*
    [Question]

    Topics
    Companies
    Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

    Only numbers 1 through 9 are used.
    Each number is used at most once.
    Return a list of all possible valid combinations. The list must not contain the same combination twice, 
    and the combinations may be returned in any order.

    

    Example 1:

        Input: k = 3, n = 7
        Output: [[1,2,4]]
        Explanation:
        1 + 2 + 4 = 7
        There are no other valid combinations.

    Example 2:

        Input: k = 3, n = 9
        Output: [[1,2,6],[1,3,5],[2,3,4]]
        Explanation:
        1 + 2 + 6 = 9
        1 + 3 + 5 = 9
        2 + 3 + 4 = 9
        There are no other valid combinations.

    Example 3:

        Input: k = 4, n = 1
        Output: []
        Explanation: There are no valid combinations.
        Using 4 different numbers in the range [1,9], 
        the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

    [Thought]
    1. 組合問題，可以透過 Backtracking 方式解決，可分為：
        -   基本回朔法
        -   剪枝回朔法


*/
class Solution {
public:

    // 紀錄單線組合
    vector<int> path;
    // 紀錄所有組合
    vector<vector<int>> results;
    /*
        k          = 組合數
        n          = 目標值
        startIndex = 下一層 for 循環搜尋的起始位置
        sum        = 已搜集的元素總和，也就是 path 裡的元素總和
    */
    void backtracking(int k, int n, int startIndex, int sum) {
        // 終止條件：如果找到 3 個數值相加等於目標值，存入 results，並返回！
        if(path.size() == k) {
            if(sum == n) results.push_back(path);
            return;
        }
        // 單層邏輯
        for(int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            backtracking(k, n, i + 1, sum);
            // 回朔部分：
            sum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return results;
    }
};
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
        -   基本回朔法  --> 檔案01
        -   剪枝回朔法  --> 檔案02


*/


class Solution {
public:

    vector<int> path;
    vector<vector<int>> results;

    void backtracking(int k, int n, int startIndex, int sum) {
        if(sum > n) return;
        
        if(path.size() == k) {
            if(sum == n) {
                results.push_back(path);
            }
        }

        for(int i = startIndex; i < n - (k - path.size()) + 1; i++) {
            sum += i;
            path.push_back(i);
            backtracking(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return results;
    }
};

int main() {
    int k = 2;
    int n = 4;
    Solution solution;
    vector<vector<int>> results = solution.combinationSum3(k , n);

    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < k; j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}
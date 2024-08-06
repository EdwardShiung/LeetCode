#include <iostream>
#include <vector>
using namespace std;

/*
    Given an array of distinct integers candidates and a target integer target, 
    return a list of all unique combinations of candidates where the chosen numbers sum to target. 
    You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. 
    Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

    

    Example 1:

        Input: candidates = [2,3,6,7], target = 7
        Output: [[2,2,3],[7]]
        Explanation:
        2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
        7 is a candidate, and 7 = 7.
        These are the only two combinations.

    Example 2:

        Input: candidates = [2,3,5], target = 8
        Output: [[2,2,2,2],[2,3,3],[3,5]]
        Example 3:

        Input: candidates = [2], target = 1
        Output: []
        

    Constraints:

        1 <= candidates.length <= 30
        2 <= candidates[i] <= 40
        All elements of candidates are distinct.
        1 <= target <= 40


    [Thought]
    1. 同樣為基本 Backtracking 模板。但要了解不同點，在於 startIndex 不需要 + 1。原因在於，本題可重複取得陣列(Candidates)數值。



*/

class Solution {
public:
    // 單條路線
    vector<int> path;
    // Results
    vector<vector<int>> results;

    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        // 如果 sum > target, return 
        if(sum > target) {
            return;
        }

        // 如果 sum = target, 將結果放入 results
        if(sum == target) {
            results.push_back(path);
            return;
        }

        for(int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            // 第四個參數不設定為 i + 1，原因在於，本題可以重複的查找
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return results;
    }
};

int main() {
    vector<int> candidates = {2, 3, 5};
    int target = 8;
        
    Solution solution;
    vector<vector<int>> results =  solution.combinationSum(candidates, target);

    for(int i  = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) {
            cout << "[" << results[i][j] << "]" << " ";
        }
        cout << endl;
    }


    return 0;
}

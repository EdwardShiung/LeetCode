#include <iostream>
using namespace std;

/*

    [Question]

    Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.

    

    Example 1:

    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output: 
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
    Example 2:

    Input: candidates = [2,5,2,1,2], target = 5
    Output: 
    [
    [1,2,2],
    [5]
    ]
    

    Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30


*/


class Solution {
public:

    // Create path to store route
    vector<int> path;
    // Create results
    vector<vector<int>> results;

    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        // sum > target, 返回
        if(sum > target) return;
        // sum == target, 將結果放在 results
        if(sum == target) {
            results.push_back(path);
            return;
        }
        // for-loop
        for(int i = startIndex; i < candidates.size(); i++) {

            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 排序 数组，方便跳过重复元素
        sort(candidates.begin(), candidates.end()); 
        backtracking(candidates, target, 0, 0);
        return results;
    }
};


int main() {
    
    vector<int> candidates = {10,1,2,7,6,1,5};

    int target = 8;

    Solution solution;

    


    return 0;
}
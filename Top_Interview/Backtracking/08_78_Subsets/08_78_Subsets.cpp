#include <iostream>
#include <vector>
using namespace std;

/*
    Given an integer array nums of unique elements, return all possible 
    subsets
    (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    

    Example 1:

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    Example 2:

    Input: nums = [0]
    Output: [[],[0]]
    

    Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.

    [Thought]:
    1. 了解 “子集” 與 “分組和切割”問題的不同
        - 子集         ：收集所有節點
        - 分組和切割    ：收集葉子節點

*/

class Solution {
public:

    vector<int> path;
    vector<vector<int>> results;

    void backtracking(vector<int> nums, int startIndex) {
        // 因為子集包含空集合
        results.push_back(path);
        // 終止條件
        if(startIndex == nums.size()) {
            return;
        }
        // 單層邏輯
        for(int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return results;
    }
};

int main() {

    Solution solution;
    vector<int> nums = {1,2,3};
    vector<vector<int>> results = solution.subsets(nums);

    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include<unordered_set>
using namespace std;

/*
    Given an integer array nums, 
    return all the different possible non-decreasing subsequences of the given array with at least two elements. 
    You may return the answer in any order.

 

    Example 1:

    Input: nums = [4,6,7,7]
    Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
    Example 2:

    Input: nums = [4,4,3,2,1]
    Output: [[4,4]]
    

    Constraints:

    1 <= nums.length <= 15
    -100 <= nums[i] <= 100

*/

class Solution {
public:
    // Create a path
    vector<int> path;
    // Create a results
    vector<vector<int>> results;

    void backtracking(vector<int>& nums, int startIndex) {
        // 終止條件：
        if(path.size() > 1) {
            results.push_back(path);
            // 這裡不用給予 return，因為要取所有節點
        }

        // 單層邏輯
            //使用 unordered_set 去重複
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++) {
            // 限制條件：
                // 1. 樹枝：所取的元素要大於子集最後一個元素才可以
                // 2. 樹層：同一層，不可重複取得
            if(!path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end()) continue;
            // 紀錄同一層，用過的元素（每一層都會清空，重新紀錄）
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return results;
    }
};

int main() {
    vector<int> nums = {4,6,7,7};
    Solution solution;
    vector<vector<int>> results = solution.findSubsequences(nums);
    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
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
private:
    vector<int> path;
    vector<vector<int>> results;

    void backtracking(vector<int>& nums, int startIndex) {
        // 終止條件：
        if(path.size() > 1) results.push_back(path);
        // 單層邏輯
        // 利用 Array 當作 hashmap
        int used[201] = {0};
        for(int i = startIndex; i < nums.size(); i++) {
            if(!path.empty() && nums[i] < path.back() || used[nums[i] + 100] == 1) {
                continue;
            }
            // 由于 nums[i] 可能為負數，因此通過 +100 將他們範圍轉為 [0, 200]，方便在 used 陣列中進行標記。
            used[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
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

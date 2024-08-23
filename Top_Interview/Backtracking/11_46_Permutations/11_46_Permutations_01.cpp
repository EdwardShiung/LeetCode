#include <iostream>
#include <unordered_set>
using namespace std;


/*
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    

    Example 1:

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Example 2:

    Input: nums = [0,1]
    Output: [[0,1],[1,0]]
     
    Example 3:

    Input: nums = [1]
    Output: [[1]]
    

    Constraints:

    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.

    [Thought]:
    1. 要了解組合、切割、排列的不同

    [Similar Question]:
    1. LeetCode 46  Permutations
    2. LeetCode 47 Permutations II

*/

class Solution {
private:
    // Create a path
    vector<int> path;
    // Create a results
    vector<vector<int>> results;

    void backtracking(vector<int>& nums, vector<bool>& used) {
        // 終止條件：
        if(path.size() == nums.size()) {
            results.push_back(path);
        }
        // 單層邏輯：
            // 因為題目說明陣列元素較小，所以可以使用 array 當作 hashmap 來紀錄已使用的元素
        for(int i = 0; i < nums.size(); i++) {
            // used 主要紀錄 path 中，已經出現過的元素。
            if(used[i] == true) continue;
            
            // 如果沒有出現在 used 中，則將其加入到hashmap紀錄中
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 創建紀錄 hashmap
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return results;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution solution;
    vector<vector<int>> results;
    results = solution.permute(nums);

    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
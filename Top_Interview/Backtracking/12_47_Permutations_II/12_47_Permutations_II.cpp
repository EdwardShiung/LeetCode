#include <iostream>
using namespace std;


/*
    Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

    

    Example 1:

    Input: nums = [1,1,2]
    Output:
    [[1,1,2],
    [1,2,1],
    [2,1,1]]
    Example 2:

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    

    Constraints:

    1 <= nums.length <= 8
    -10 <= nums[i] <= 10

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
            return;
        }
        // 單層循環
        for(int i = 0; i < nums.size(); i++) {

            // 如果同一層已經使用過了，就不可以在使用了
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

            // 如果同一支樹枝沒使用過，則開始處理
            if(used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return results;
    }
};


int main() {

    vector<int> nums = {1,1,2};

    Solution solution;
    vector<vector<int>> results = solution.permuteUnique(nums);

    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results.size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
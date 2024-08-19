#include <iostream>
#include <vector>
// #include <boolean>
using namespace std;

/*
    Given an integer array nums that may contain duplicates, return all possible 
    subsets
    (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:

    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    Example 2:

    Input: nums = [0]
    Output: [[],[0]]
    

    Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10

    [Thought]:
    1. 了解與LeetCode 78 Subsets 差異
        - 本題題目給予的陣列值，可能重複
        - 因為要找出相鄰的值，所以要先”排序“ 
    2. 了解：
        ”樹層重複“
        “樹枝重複”
*/

class Solution {
public:
   // Create a path
   vector<int> path;
   // Create a results
   vector<vector<int>> results;

   void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
    // 子集包含空集合
    results.push_back(path);
    // 終止條件：（因為不是只搜集葉子節點，因此這部分可省略）
    if(startIndex == nums.size()) {
        return;
    }
    // 單層邏輯：
    for(int i = startIndex; i < nums.size(); i++) {
        // 這邊同一層邏輯中，不能有重複的
        // used == false && i > 0 && nums[i] == nums[i - 1] --> 樹層重複
        // used == true && i > 0 && nums[i] == nums[i - 1] --> 樹枝重複
        if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, i + 1, used);
        used[i] = false;
        path.pop_back();
    }
   }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return results;
    }
};

int main() {
    
    vector<int> nums = {1,2,2};

    Solution solution;
    vector<vector<int>> results = solution.subsetsWithDup(nums);
    
    for(int i = 0; i < results.size(); i++) {
        for(int j = 0; j < results[i].size(); j++){
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
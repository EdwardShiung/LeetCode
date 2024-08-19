#include <iostream>
#include <unordered_set>
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
    
    3. 本題共有三種解法
        - 方法一： 利用 used 追蹤 “樹層重複” 和 “樹枝重複”  --> 檔案 01
        - 方法二： 利用 set                             --> 檔案 02
        - 方法三： 同方法一，但不使用 used                --> 檔案 03
    
*/
class Solution {
public:
    // Create a path
    vector<int> path;
    // Create a results
    vector<vector<int>> results; 

    void backtracking(vector<int> nums, int startIndex) {
        // 子集包含空集合
        results.push_back(path);
        // 終止條件：（因為不是只搜集葉子節點，因此這部分可省略）
        if(startIndex == nums.size()) return;
        // 單層邏輯：
        // 使用 unordered_set 
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++) {
            // 利用 find 和 end 方法： 
            if(uset.find(nums[i]) != uset.end()) continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }   
    }

    vector<vector<int>> subsetsWithDup(vector<int> nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
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
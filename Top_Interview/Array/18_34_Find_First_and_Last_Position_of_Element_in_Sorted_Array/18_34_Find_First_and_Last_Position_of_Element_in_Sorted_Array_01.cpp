#include <iostream>
using namespace std;

/*
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

        
[Thought]:

1. Find the right and left border
    - 1st Situation
        The target is not in the nums, so it return {-1, -1}

    - 2nd Situation
        The target is in the nums but no element same with target. It return {-1, -1}

    - 3rd Situation
        The target is in the nums, and still have the element with target
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);

        // 1st Situation
        if(leftBorder == -2 || rightBorder == -2) return {-1, -1};

        // 3rd Situation
        if(rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};

        // 2nd Situation
        return {-1, -1};
    }

private:
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1;
        // Using a random to initialize rightBorder
        int rightBorder = -2;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(nums[middle] > target) {
                right  = middle - 1;
            }else {
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while(left <= right) {
            int middle = left + (right - left) / 2;

            // The biggest different for here!!
            if(nums[middle] >= target) {
                right =  middle - 1;
                leftBorder = right;
            }else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    
    Solution sol;
    vector<int> results =  sol.searchRange(nums, target);

    for(int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
}
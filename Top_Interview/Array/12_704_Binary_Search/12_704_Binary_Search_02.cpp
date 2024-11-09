#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.

*/

// 1st Solution 
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         // Brutal force method
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == target) return i;
//         }
//         return -1;
//     }
// };


// 2nd Solution
// class Solution {
// public:
//     // Binary Search
//     // 1st Binary Search Style
//     int search(vector<int>& nums, int target) {
//         int left = 0;
//         // Right index will determine the "middle" and loop limitation.
//         // 1st Style: LC & RC [left, right] 
//         // 左閉 右閉 
//         int right = nums.size() - 1;

//         // Due to LC & RC, we have give the "equal" character to the limitation.
//         while(left <= right) {
//             int middle = (left + right) / 2;
            
//             if(nums[middle] > target) right = middle - 1;
            
//             if(nums[middle] < target) left = middle + 1;

//             if(nums[middle] == target) return middle;
//         }
//         return -1;
//     }
// };

// 3rd Solution
class Solution {
public:
    // Binary Search
    // 2nd Binary Search Style
    int search(vector<int>& nums, int target) {
        int left = 0; 
        // Right index will determine the "middle" and loop limitation.
        // 1st Style: LC & RO [left, right)
        // 左閉 右開
        int right = nums.size();
        // Due to the LC & RO, we don't need to give the limitation "equal" sign.
        while(left < right) {
            int middle = (left + right) / 2;

            if(nums[middle] > target) right = middle;

            if(nums[middle] < target) left = middle + 1;

            if(nums[middle] == target) return middle;
        }
        return -1;
    }
};


int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    Solution solution;
    int results = solution.search(nums, 9);
    cout << results << endl;
    return 0;
}
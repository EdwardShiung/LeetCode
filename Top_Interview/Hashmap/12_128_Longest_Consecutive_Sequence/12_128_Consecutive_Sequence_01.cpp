#include <iostream>
using namespace std;


/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109


    [Thought]:
    1. Using the 3 nested loop. (Brute Force)
    2. The time complexity is O(N^3), which will be time limited exceeded(TLE).
    3. The space complexity is O(1).

*/


class Solution {
    // 使用這個 private function 原因在於：當前元素為 n 時，希望找到陣列 nums 中，有 n + 1 這個數值
    // 因此，target 就是在找尋陣列中，下一個數值。
private:
    bool longestConsecutive(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                return true;
            }
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        // Edge Cases
        if(nums.size() <= 1) return nums.size();
        // Set a Result Value (Get the longest length)
        int result = 0;

        // Using the loop to find the longest consecutive value
        for(int num : nums) {
            // currentValue
            int currentVal = num;
            // currentConsecutiveSequence
            int currentConsecutiveSequence = 1;
            // Using while loop to find the Next Value
            // While Limitation is: whether could finding the next value  or not
            while(longestConsecutive(nums, currentVal + 1)) {
                currentConsecutiveSequence += 1;
                currentVal += 1;
            }
            result = max(result, currentConsecutiveSequence);
        }
        return result;
    }
};
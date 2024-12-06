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

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        if(nums.size() <= 1) return nums.size();

        // Sorted the nums array
        sort(nums.begin(), nums.end());

        //Using the for-loop to get the result
        // Record the consecutiveSequence
        int currSequence = 1;
        for(int i = 1; i < nums.size(); i++) {
            // 只處理前後不同的數值！
            if(nums[i] != nums[i - 1]) {
                if(nums[i] == nums[i - 1] + 1) {
                    currSequence++;
                }else {
                    result = max(result, currSequence);
                    currSequence = 1;
                }
            }
        }
        return max(result, currSequence);
    }
};
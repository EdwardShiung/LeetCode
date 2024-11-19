#include <iostream>
using namespace std;

/*

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105

*/


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        // Return Results
        long long results = 0;

        // Temp Sum
        long long temp = 0;

        // SlowPointer
        int slowPointer = 0;

        // Using Unorderedmap to store the value
        unordered_map<int, int> numsSchema;

        // Using the sliding window to solve the problem
        for(int i = 0; i < nums.size(); i++) {
            
            // Record the numbers and frequency
            numsSchema[nums[i]]++;
            // Record the temp sum
            temp += nums[i];


            // Verify the numb[i] of quantity
            // Close the left window
            while(numsSchema[nums[i]] > 1) {
                numsSchema[nums[slowPointer]]--;
                temp -= nums[slowPointer];
                slowPointer++;
            }

            // sublength == k
            if(i - slowPointer + 1 == k) {
                results = max(results, temp);
                numsSchema[nums[slowPointer]]--;
                temp -= nums[slowPointer];
                slowPointer++;
            }

        }
        return results;
    }
};
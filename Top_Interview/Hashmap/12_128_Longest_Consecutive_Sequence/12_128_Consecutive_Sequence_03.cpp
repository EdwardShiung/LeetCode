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
        // Set the result
        int result = 0;
        // Using the unordered_map to store the nums
        unordered_map<int, bool> record;
        
        // for-loop to record all numbers is true
        for(int i = 0; i < nums.size(); i++) record[nums[i]] = true;
        // for-loop to note the number which has previous number
        // 如果發現，某個陣列的值，他有前一筆，則標記，它不可以為起始點，因此設為 false
        for(int j = 0; j < nums.size(); j++) {
            if(record.count(nums[j] - 1)) {
                record[nums[j]] = false;
            }
        }

        // Using for loop to get the longest consecutive sequence
        for(int k = 0; k < nums.size(); k++) {
            // 只有標記為 true 的 number，才有可能為起始點
            if(record[nums[k]] == true) {
                // Set a count
                int count = 0;
                // Set a increase value 
                int increaseValue = 0;
                while(record.count(nums[k] + increaseValue)) {
                    count++;
                    increaseValue++;
                }
                result = max(result, count);
            }
        }

        return result;

    }
};
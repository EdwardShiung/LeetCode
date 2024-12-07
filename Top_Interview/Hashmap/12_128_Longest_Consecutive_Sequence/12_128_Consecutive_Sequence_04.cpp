#include <iostream>
#include <unordered_set>
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
        // Set a result
        int result = 0;
        // Using set to store unique number
        unordered_set<int> setRecord;
        // Using for-loop to store in the set
        for(int num : nums) setRecord.insert(num);
        // Using for-loop to find the longest consecutive sequence
        for(int num : nums) {
            // 透過 Set，去查看 num 是否有前一個數值
            // 如果沒有前一個數值，代表可能為起點
            if(setRecord.count(num - 1)  == false) {
                // 以當前 num 為起點，開始統計
                int currentNum = num;
                // 計數
                int count = 1;
                while(setRecord.count(currentNum + 1)) {
                    currentNum++;
                    count++;
                }
                result = max(result, count);
            }
        }
        return result;
    }
};
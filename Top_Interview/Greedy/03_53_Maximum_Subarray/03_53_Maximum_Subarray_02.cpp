#include <iostream>
using namespace std;

/*

    Given an integer array nums, find the subarray
    with the largest sum, and return its sum.

    Example 1:

    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.
    Example 2:

    Input: nums = [1]
    Output: 1
    Explanation: The subarray [1] has the largest sum 1.
    Example 3:

    Input: nums = [5,4,-1,7,8]
    Output: 23
    Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

    Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    

    Follow up: If you have figured out the O(n) solution,
    try coding another solution using the divide and conquer approach, which is more subtle.

    [Thought]
    1. 暴力解 -- file 01
        -- Time Limit Exceeded
    2. Greedy Method -- file 02
        -- 只取正的元素
    3. DP Method -- file 03
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if(result < count) result = count;

            if(count <= 0) count = 0;
        }
        return result;
    }
};


int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution solution;

    int result = solution.maxSubArray(nums);

    cout << result << endl;


    return 0;
}
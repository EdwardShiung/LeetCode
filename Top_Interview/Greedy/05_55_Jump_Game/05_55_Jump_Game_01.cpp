#include <iostream>
using namespace std;


/*
    You are given an integer array nums. You are initially positioned at the array's first index, 
    and each element in the array represents your maximum jump length at that position.

    Return true if you can reach the last index, or false otherwise.

    

    Example 1:

    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Example 2:

    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, 
    which makes it impossible to reach the last index.
    

    Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 105

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 只有一個元素必定能達到
        if(nums.size() == 1) return true;
        // 覆蓋程度
        int cover = 0;
        // 注意：這裡是 <=
        for(int i = 0; i <= cover; i++) {
            // 關鍵點！！
            cover = max(i + nums[i], cover);
            if(cover >= nums.size() - 1) return true;
        }
    return false;
    }
};

int main() {
    
    vector<int> nums = {2,3,1,1,4};

    Solution solution;

    bool result = solution.canJump(nums);
    
    cout << result << endl;

    return 0;
}
#include <iostream>
using namespace std;

/*
    You are given a 0-indexed array of integers nums of length n. 
    You are initially positioned at nums[0].

    Each element nums[i] represents the maximum length of a forward jump from index i. 
    In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n
    Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

    

    Example 1:

    Input: nums = [2,3,1,1,4]
    Output: 2
    Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Example 2:

    Input: nums = [2,3,0,1,4]
    Output: 2
    

    Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].

    [Thought]
    1. 本題與 55 題最大差異，在於： 
        - LeetCode 只要找到一組，可以跳到終點的，就立刻返回
            - LeetCode 本題要找，步數最少的組合

*/

class Solution {
public:

    int jump(vector<int>& nums) {

        // 如果只有一個元素，直接返回 0
        if(nums.size() == 1) return 0;
        
        // 利用 cur 和 next 代表當前覆蓋範圍
        
        // 初始化：cur 和 next 覆蓋都為 0 
        int curDistance = 0;
        int nextDistance = 0;
        // 紀錄走的最大部署
        int result = 0;

        for(int i = 0; i < nums.size(); i++) {
            nextDistance = max(i + nums[i], nextDistance);
            if(i == curDistance) {
                result++;
                curDistance = nextDistance;
                if(nextDistance >= nums.size() - 1) break;
            }
        }

        return result;
    }
};

int main() {
    
    vector<int> nums = {2,3,1,1,4};

    Solution solution;

    int result = solution.jump(nums);

    cout << result << endl;

    return 0;
}
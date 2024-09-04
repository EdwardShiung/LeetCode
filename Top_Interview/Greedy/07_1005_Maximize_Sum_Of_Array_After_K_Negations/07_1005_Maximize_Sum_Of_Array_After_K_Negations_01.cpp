#include <iostream>
using namespace std;

/*

    Given an integer array nums and an integer k, modify the array in the following way:

    choose an index i and replace nums[i] with -nums[i].
    You should apply this process exactly k times. You may choose the same index i multiple times.

    Return the largest possible sum of the array after modifying it in this way.

    

    Example 1:

    Input: nums = [4,2,3], k = 1
    Output: 5
    Explanation: Choose index 1 and nums becomes [4,-2,3].

    Example 2:

    Input: nums = [3,-1,0,2], k = 3
    Output: 6
    Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].

    
    Example 3:

    Input: nums = [2,-3,-1,5,-4], k = 2
    Output: 13
    Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
    

    Constraints:

    1 <= nums.length <= 104
    -100 <= nums[i] <= 100
    1 <= k <= 104

    [Thought]
    1. 使用兩次貪心
    2. 先將陣列中的數值，透過絕對值進行排序
            EX:
                    -3, -1, 0, 2
            透過 sort函數和“自定義比較函數”，進行排序
                --> 自定義比較函數，請使用絕對值來排
            結果為：
                    -3, 2, -1, 0
        
        --> 原因：
            1. 如果元素值中，沒有”負數“，則將所有”取反“，全部取最小的
            2. 如果元素中有“負數”，則透過絕對值進行排序，可以先將“負數”先取反


*/


class Solution {

    static bool compare(int a, int b) {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //Step 1: 透過絕對值比較個元素，進行排序
        sort(nums.begin(), nums.end(), compare);
        //Step 2: 遍歷元素：當元素遇到負數，則取反
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        //Step 3: 如果 K  尚未用完，且 K 為基數
        // 因為透過前面的排序，知道絕對值元素中的最小值，會在陣列中的最後一個
        if(k % 2 == 1) nums[nums.size() - 1] *= -1;

        //Step 4: 將元素累加
        int results =0;
        for(int num: nums) {
            results += num;
        }
        return results;
    }
};

#include <iostream>
using namespace std;

/*
    A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

    For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
    In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
    The first is not because its first two differences are positive, 
    and the second is not because its last difference is zero.
    A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, 
    leaving the remaining elements in their original order.

    Given an integer array nums, return the length of the longest wiggle subsequence of nums.

    

    Example 1:

    Input: nums = [1,7,4,9,2,5]
    Output: 6
    Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).

    Example 2:

    Input: nums = [1,17,5,10,13,15,10,5,16,8]
    Output: 7
    Explanation: There are several subsequences that achieve this length.
    One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

    Example 3:

    Input: nums = [1,2,3,4,5,6,7,8,9]
    Output: 2
    

    Constraints:

    1 <= nums.length <= 1000
    0 <= nums[i] <= 1000


    [Thought]
    1. 考慮問題：
        - preDiff >= 0 && curDiff < 0
        - preDiff <= 0 && curDiff > 0
            - 相鄰有平坡
                - 考慮刪除點
                - preDiff = 0  
            - 首、尾元素
                - 都算坡度！！（題目第三個例子）
                    - 至少要三個元素才能計算，但如果只有兩個元素，不到三個情況下，就不能計算
                        - 可以利用：默認最左邊就是有擺動
                        Ex: [2,2]
                            --> 但是要默認還有一個最左邊的元素
                                2-2-2

            - 平坡上揚
            EX: 1-2-2-2-3-4
            --> 但題目需要一個 "+"，一個 "-"
*/


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        // 題目已說明，當元素 <= 2 時，回應元素個數
        if(nums.size() <= 1) return nums.size();

        // 前面兩個差值
        int preDiff = 0;
        // 後面兩個差值
        int curDiff = 0;
        // 結果紀錄
        int results = 1;

        for(int i = 0; i < nums.size() - 1 ; i++) {
            curDiff = nums[i + 1] - nums[i];
            if(preDiff >=0 && curDiff < 0 || preDiff <= 0 && curDiff > 0) {
                results++;
                preDiff = curDiff;
            }
        }
        return results;
    }
};

int main() {
    
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};

    Solution solution;

    int results = solution.wiggleMaxLength(nums);

    cout << results << endl;

    return 0;
}
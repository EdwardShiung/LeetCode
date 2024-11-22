#include <iostream>
using namespace std;



/*
Given an integer array nums, 
return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? 
(The output array does not count as extra space for space complexity analysis.)


    [Thought]:
    1. The problem description is very clear that we can't use "division operation".
        - which means we could not product all elements and using division operation with nums[i].
    2. The time complexity should be O(n).
        - which means that we could not use sliding window to solve the problem.
    3. The problem description reminds me that the product of any prefix and suffix of nums is guaranteed to fit in a 32-bit integer.
        - which reminds me using "commutative property of multiplication" in production operation.

PS.
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
        這句話的意思是：**`nums` 陣列中任何一段前綴或後綴的元素乘積都能被 32 位整數（`int32`）表示**，也就是說，
        無論怎麼計算，結果都不會超過 `int32` 的範圍。

        在程式設計中，32 位整數的範圍是：
        - **有符號整數**：`-2^31 (-2,147,483,648)` 到 `2^31 - 1 (2,147,483,647)`。
        - **無符號整數**：`0` 到 `2^32 - 1 (4,294,967,295)`。

        由於這裡的元素乘積被保證可以用 32 位有符號整數表示，因此你在實現演算法時可以放心，不用擔心溢出問題，
        也不需要特別處理結果超出範圍的情況。

        ### 舉例說明：
        假設 `nums = [1, 2, 3, 4]`：
        - 前綴乘積：`[1, 1*2, 1*2*3, 1*2*3*4]` -> `[1, 2, 6, 24]`
        - 後綴乘積：`[2*3*4, 3*4, 4, 1]` -> `[24, 12, 4, 1]`

        這些乘積的結果都在 32 位整數範圍內，因此保證不會溢出。

        如果沒有這樣的保證，你就需要額外考慮如何避免溢出問題（例如使用大數字計算或進行範圍檢查）。
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // the size of the nums
        int lengthNums = nums.size();
        // store the results
        vector<int> results(lengthNums, 0);
        // Using a temp to set the default
        int temp = 1;

        // Left accumulated production operation
        for(int i = 0; i < lengthNums; i++) {
            results[i] = temp;
            temp *= nums[i];
        }
        /*
        Ex: [1, 2, 3, 4]
        Left:
        --> [1, 1, 2, 6]
        Right:
        --> [24, 12, 8, 6]
        */ 

        // Adjust temp to 1
        temp = 1;
        // Right accumulated production operation
        for(int i = lengthNums - 1; i >= 0; i--) {
            results[i] *= temp;
            temp *= nums[i];
        }
        return results;
    }
};



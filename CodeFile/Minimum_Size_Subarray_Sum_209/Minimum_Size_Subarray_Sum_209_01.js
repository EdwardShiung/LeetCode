/* leetCode_209: Minimum Size Subarry Sum_01
Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
 */
//[1st Trial]
var minSubArrayLen = function(target, nums) {
        let sum = 0;
        let i = 0;
        let subarryLength = 0;
        let result = Infinity;              // understand how to use the Infinity in JavaScript
    for(let j = 0; j < nums.length; j ++){

        sum += nums[j];

        // the core of the sliding window
        while(sum >= target){
            subarryLength = (j - i + 1);
            // console.log("subarryLength: "+subarryLength);

            result = Math.min(result, subarryLength);

            // console.log("result: "+result);
            sum -= nums[i];                 // the core of the sliding window
            i ++;
        }
    }

    return result === Infinity ? 0 : result;
};
/*
    1. Subarray must consecutive in the array.
        Ex: Array = [1,2,3]
            --> SubArray = {1},{2},{3},{1,2},{2,3},{1,2,3}

    2. Double pointer (starting pointer & ending pointer) --> "Sliding Window"
        - starting pointer is "i"; ending pointer is "j"
        - once the sum >= target, starting pointer move again.
        - once get the subarray length, compare to the previous subarray length.
            --> Using result to save the final length.

    3. Understanding the core of the sliding window


    [Results]:
    Runtime     171ms;      Beats 9.77% of users with JavaScript;
    Memory      52.77mb;    Beats 5.01% of users with JavaScript;

    [Time Complexity]: O(n)
    [Space Commplexity]: O(1)

    [Key Point]
    Don't assume that putting a while inside a for loop immediately makes it O(n^2).
    The key factor is to observe how many times each element is being manipulated.
    With the sliding window approach, each element is operated upon once as it enters the window and once as it exits the window.
    Since each element is manipulated twice, the time complexity is 2 × n, which simplifies to O(n).
 */

let nums = [5,1,3,5,10,7,4,9,2,8];
let targets = 15;

minSubArrayLen(targets, nums);
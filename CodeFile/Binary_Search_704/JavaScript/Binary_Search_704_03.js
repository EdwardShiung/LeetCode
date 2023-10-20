/* leetCode_704: Binary Search_03
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

Constraints:
All the integers in nums are unique.
nums is sorted in ascending order.
 */
//[2nd]:Binary Search Algorithm
/**
 * There are two point in the question:
 *  1. The numbers are sorted in the array
 *  2. Each number is unique in the array
 *  --> Using the binary search algorithm
 *  --> find the middle index and observe the target number is bigger than middle number or not.
 * */
//[Sol_02]: [left, right] --> include left and right
var search = function(nums, target){

    let left = 0;
    let right = nums.length -1;                //[left, right)
    while(left <= right){                    //can't  <= because left != right

        let middle = left + ((right - left) >> 1);

        if(nums[middle] > target){
            right =  middle -1;              //target is in the right [left, right]
        }else if(nums[middle] < target){
            left  = middle + 1;             //target is in the right [middle + 1, right]
        }else{
            return middle;                  //nums[middle] == target
        }
    }
    return -1;                          //target is not existed
}

/**
    [Results]:
    Runtime     54ms;       Beats 81.96% of users with JavaScript;
    Memory      45.28mb;    Beats 28.56% of users with JavaScript;

    [Time Complexity]: O(n)
 */

/* leetCode_704: Binary Search_02
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
//[2nd Trian]:Binary Search Algorithm
/**
 * There are two point in the question:
 *  1. The numbers are sorted in the array
 *  2. Each number is unique in the array
 *  --> Using the binary search algorithm
 *  --> find the middle index and observe the target number is bigger than middle number or not.
 * */
//[Sol_01]: [left, right) --> include left but not include right
var search = function(nums, target){

    let left = 0;
    let right = nums.length;                //[left, right)
    while(left < right){                    //can't  <= because left != right

        let middle = left + ((right - left) >> 1);

        if(nums[middle] > target){
            right =  middle;                //don't need to + 1 because target is in the left [left, right)
        }else if(nums[middle] < target){
            left  = middle + 1;             //target is in the right, so [middle + 1, right)
        }else{
            return middle;                  //nums[middle] == target
        }
    }
    return -1;                          //target is not existed
}

/*
    1. There are lots of way to find the middle number by Javascript function
        --> should be understand the Math function, >>, << and so on.
    2. The first time I write like that:
            let middle = 0;
            let left = 0;
            let right = 0;
            middle = nums.length / 2
            while(left < right){
                if(middle > target){
                    right =  middle - 1;
                    console.log(right);
                }else if(middle < target){
                    left  = middle;
                    console.log(left);
                }else{
                    return nums[middle];
                }
            }
            --> you see, I make a big mistake: it will not enter the while loop!!!

    3. understand the difference between [left, rigth) and [left, right]
            --> if count length, left can't equal to right. (out of the index)

    [Results]:
    Runtime     68ms;       Beats 22.23% of users with JavaScript;
    Memory      45.10mb;    Beats 49.35% of users with JavaScript;

    [Time Complexity]: O(n)

 */

let list = [-1,0,3,5,9,12];
// console.log('length of nums is '+ nums.length)
let target = 2;

search(list, target);

// let num = 5;
// console.log(num / 2); //2.5
// // try to set the absoluted value

// //try to use Math function
// console.log(Math.round(num / 2));

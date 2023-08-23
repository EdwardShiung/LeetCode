//[1st]
var search = function (nums, target){
    for(let i = 0; i < nums.length; i ++){
        if(nums[i] == target ){
            console.log(target + ' exists in nums and its index is '+ i);
            return i;
        }else if(i == nums.length - 1){
            console.log(target + ' does not exist in nums');
            return -1;
        }
    }
}

let list = [-1,0,3,5,9,12];
// console.log('length of nums is '+ nums.length)
let target = 9;

search(list, target);

//the Process what I met in first time:
/*
    1. I forget the length of array in JS
    --> [Solved] length function
    2. it doesn't run in the if statement
    --> [Solved] I type the return on the else statement, so the first round will over. That's why only first element is validated.
    3. I met another problem is the loop have to run all over the element but the problem said that once it finding out, it will stop. (All the integers are unique.)
    --> [Solved] Set the limited in else if statement

    [Results]:
        Runtime     70ms;       Beats 16.09%;
        Memory      45.35mb;    Beats 19.08 of users with JavaScript
        Time Complexity O(n);
 */

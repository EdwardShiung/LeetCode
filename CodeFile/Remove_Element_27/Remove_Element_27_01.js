var removeElement = function(nums, val) {

    let slow = 0;

    for(let i = 0; i < nums.length; i ++){
        if(nums[i] != val){
            nums[slow] = nums[i];
            slow ++;
        }
    }
    return slow;
};


let nums = [0,1,2,2,3,0,4,2], val = 2;
// let nums = [3,2,2,3], val = 3;

removeElement(nums, val);


/*
        1. It should understand about fast pointer and slow pointer to solve this problem
        2. It's not delete the element in array; it just cover the element.

        [Results]:
        Runtime     63ms;       Beats 23.89%;
        Memory      42.09mb;    Beats 41.69 of users with JavaScript
 */
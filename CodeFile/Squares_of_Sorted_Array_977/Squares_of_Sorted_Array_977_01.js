var sortedSquares = function(nums) {
    let list = new Array(nums.length).fill(0);
    let index = nums.length - 1;

    let k = 0;

    // console.log(nums);
    for(let i = nums.length - 1; i >= k; i --){
        console.log("i"+i);
        if((nums[k] * nums[k]) < (nums[i] * nums[i])){
            list[index] = nums[i] * nums[i];
            index --;
        }else{
            list[index] = nums[k] * nums[k];
            index --;
            k ++;
            i ++;
        }
    }
    // console.log(list);
    return list;
};



/*
    1. I thought about brute force solution in my first time but there's a limitation in time complexity.
        --> O(n)
        --> It cannot use the double loop.

    2. I set too complicated solution in my first trial.
            var sortedSquares = function(nums) {
            let list = [];
            let k = 0;
            if(nums[0] > nums[nums.length - 1]){
                for(let i = nums.length - 1; i > 0 ; i --){
                    list[k++] = nums[i] * nums[i];
                }
                console.log(list);
                return list;
            }else{
                for(let i = 0; i < nums.length; i ++){
                    list[k++] = nums[i] * nums[i];
                }
                console.log(list);
                return list;
            }
        };

    3. Try to think about using third pointer in one loop
        --> I forget to initialize value for array in the first time.

            let list = new Array(nums.length).fill(0);

        --> left and right pointer to point the nums array.

        --> I add third pointer for resulted array.

    [Results]:
    Runtime     322ms;      Beats 5.92%;
    Memory      42.09mb;    Beats 5.04% of users with JavaScript

    --> The results are not good in time complexity and space complexity.

 */


let nums = [-4,-1,0,3,10];
// let nums = [-7,-3,2,3,11];

sortedSquares(nums);
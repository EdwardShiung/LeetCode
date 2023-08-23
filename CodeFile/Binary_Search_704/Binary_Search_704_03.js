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
        Runtime     54ms;       Beats 81.96%;
        Memory      45.28mb;    Beats 28.56 of users with JavaScript
        Time Complexity O(logn);
 */

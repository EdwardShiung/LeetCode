
//[2nd]: double for loop
var removeElement = function (nums, val){

    let size = nums.length;

    for(let i = 0; i <  size; i ++){
        if(nums[i] === val){

            for(let j = i + 1; j < size; j ++){
                nums[j - 1] = nums[j];
            }
            i --;
            size --;

        }
    }
    console.log(size);
    return size;
}


let nums = [3,2,2,3];
let val = 3;
removeElement(nums, val);
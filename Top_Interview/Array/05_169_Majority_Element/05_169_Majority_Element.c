#include<stdio.h>

int majorityElement(int* nums, int numsSize);

int main(){
    int nums[] = {2,2,1,1,1,2,2};
    int numsSize = 7;
    majorityElement(nums, numsSize);
}



/*
    The approach to this problem.

    Method_01:  Voting Method

    flag = nums[0]      //3
    count ++;
    nums = [3,2,3]

    1st:
                nums = [3,2,3]
    i Pointer(0)        ^
                nums[0] = flag;
                count ++
            
            Explain:
                The first element is the same with flag, so we need to add one more.
                count(1)
    
    2nd:
                nums = [3,2,3]
    i Pointer(1)          ^
                nums[1] != flag;
                count --
            
            Explain:
                The first element is the different with flag, so we need to deduct one.
                count(0)

        count(0)

            Explain:
                Because of count == 0, so we need to change the flage.
                flag = nums[1+1]
        
    
    3rd:
                nums = [3,2,3]
    i Pointer(2)            ^
                nums[2] == flag;
                count ++

            Explain:
                The first element is the same with flag, so we need to add one.
                count(0)                
        count(1)   

*/

int majorityElement(int* nums, int numsSize){ 

    int flag = nums[0];
    int count = 0;
    int index = 0;

    while(index < numsSize){
        if(nums[index] == flag){
            count ++;
        }else{
            count --;
            if(count <= 0){
                flag = nums[index + 1];
            }
        }
        index ++;
    }
    printf("%d", flag);
    return flag;
}


//[Method_02]
//Below method will cause time limited exceeded.
/*
int majorityElement(int* nums, int numsSize){
    
    int count = 0;
    int index = 0;

    while(index < numsSize){
        for(int i = 1; i < numsSize; i ++){
            if(nums[i] == nums[index]){
                count ++;
            }
        }
        if(count >= numsSize / 2){
            printf("%d", nums[index]);
            break;
        }
        count = 0;
        index ++;
    }

    return nums[index];

}
*/



/*
[Thought]:

The initial approach might be to use nested loops to track the count of occurrences.
However, the requirements specify that the time complexity should not exceed O(n), which means that you need to use the liner time algorithms.
Using nested loops would result in a time complexity of O(n^2), leading to a time limited exceeded error.

[Key Point]:

To solve the array problem, one useful method is the "Voting Method".
Simply pick one element from the array and use another variable to track the count of occurrences.
If the tracking variable shows positive, it means this number appears more frequently than any other.

*/

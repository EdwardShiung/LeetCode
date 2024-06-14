#include <stdio.h>



int removeDuplicates(int* nums, int numsSize);

int main(){
    //1st test case:
    // int nums[] = {1,2,2,2,3};
    // int numsSize = 5;

    //2nd test case:
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = 10;
    removeDuplicates(nums, numsSize);
}

/*
    The approach to this problem.

    Test Case 01:

    set index = 1

    1st:
                [1,2,2,2,3]
    1st Point    ^
    2nd Point      ^
    index(1)
                nums[index] = nums[1st + 1]
                index ++;

                --> nums Array ==> [1,2]
    2nd:
                [1,2,2,2,3]    
    1st Point      ^                    
    2nd Point        ^                  
    index(2)          

    3rd:
                [1,2,2,2,3]    
    1st Point        ^                    
    2nd Point          ^                  
    index(2)         
    
    4th:
                [1,2,2,2,3]
    1st Point          ^
    2nd Point            ^
    index(2)
                nums[index] = nums[1st + 1]
                index ++;
                --> nums Array ==> [1,2,3]
                ---> index == 3

*/

int removeDuplicates(int* nums, int numsSize){

    int index = 1;
    for(int i = 0; i < numsSize - 1; i ++){
        if(nums[i + 1] != nums[i]){
            nums[index] = nums[i + 1];
            index ++;
        }
    }
    printf("%d", index);
    return index;
}


/*
    遇到的問題：
    1. 回圈的終止條件，到底是 <= 還是 < 呢？
*/
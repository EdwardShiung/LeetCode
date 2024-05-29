#include <stdio.h>
#include <stdbool.h>


#define max(a, b) ((a > b) ? a : b);

bool canJump(int* nums, int numsSize);

int main(){


}


/*
    The approach to this problem.

    Example_01:
    1st: 
    nums =  [2,3,1,1,4]
               ^
                 ------
            [2,3,1,1,4]
                     ^    --> Completed!
    
    Example_02:
    1st:
    nums =  [2,4,1,1,4]
               ^
                 ------
             -
            [2,4,1,1,4]
             ^
    2nd:
    nums =  [2,4,1,1,4]
                 ^
            [2,4,1,1,4]
                   ^     
    3th:
    nums =  [2,4,1,1,4]
                 ^
            [2,4,1,1,4]
                     ^     --> Completed!    

    Approach:
    Only care about the covering.
    局部推論全局 -->  Greedy
    找尋覆蓋的下標!!

*/



bool canJump(int* nums, int numsSize){
    //找尋起點下標：
    int cover = 0;
    if(numsSize == 1) return true;

    // 更新 cover (從第i出發能到達的最大值)
    for(int i = 0; i <= cover; i ++){
        cover = max(i + nums[i], cover);

        if(cover >= numsSize - 1) return true;
    }
    return false;
}



/*
    [Thought]:
    1. I have to review:
        a. stdbool.h
        b. Greedy Approach

*/
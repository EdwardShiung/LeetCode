#include <stdio.h>
#include <stdbool.h>


#define max(a, b) ((a > b) ? a : b);

bool canJump(int* nums, int numsSize);

int main(){


}


/*
    [Method_01]

    The approach to this problem.

    nums =      [2,3,1,1,4]
    cover = 0

    1st:
        i = 0 
        nums =      [2,3,1,1,4]
        cover = 0    ^

        Explain:
        1.
                Maximum the coverage by nums[i]
                cover = max(0 + nums[0], 0)

                             0 1 2 3 4
                nums =      [2,3,1,1,4]                
                             -----   
                cover = 2

        2.      Coverage still not reach the endpoint.
            

    2nd:
        i = 1 
        nums =      [2,3,1,1,4]
        cover = 2      ^

        Explain:
        1.
                Maximum the coverage by nums[i]
                cover = max(1 + nums[1], 0)

                             0 1 2 3 4
                nums =      [2,3,1,1,4]                
                               --------                   
                cover = 4

        2.      Coverage still reach the endpoint, stop!

*/



//Method_01
bool canJump(int* nums, int numsSize){
    
    if(numsSize < 2) return true;

    //Initialize the maximum coverage：
    int cover = 0;

    // Update the maximum coverage:
    for(int i = 0; i <= cover; i ++){

        //By using the index, we can update the coverage until to the endpoint.
        cover = max(i + nums[i], cover);

        //If the maximum coverage reaches the endpoint, stop!
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
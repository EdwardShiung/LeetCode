#include <stdio.h>


#define max(a,b) ((a > b) ? a : b);

int jump(int*nums, int numsSize);


int main(){

}

/*
    The approach to this problem.

    1st:            
                             0 1 2 3 4
    nums =                  [2,3,1,1,4]
    i = 0                    ^
    nums[0] = 2
    curCoverDistance = 0;
    recordStep = 0;
    nextCoverDistance = 0;

        Explain: 
        1. Update the maximum distance that can be covered in the next step.
                max(nums[0] + 0 = 2, nextCoverDistance = 0)
                                 0 1 2 3 4
        nums =                  [2,3,1,1,4]
                                -----
        nextCoverDistance = 2
        2. Determine the minimum distance for the current step.
            if i == curCoverDistance
                recordStep ++;
        
        recordStep = 1;

        3. Update the index of the current maximum distance.
            curCoverDistance = nextCoverDistance;
        curCoverDistance = 2

        4. Check if the maximum distance has been reached, and if the endpoint is reached, stop immediately.
            --> 尚未達到終點！！           

    2nd:            
                             0 1 2 3 4
    nums =                  [2,3,1,1,4]
    i = 1                      ^
    nums[1] = 3
    curCoverDistance = 2;
    recordStep = 1;
    nextCoverDistance = 2;

        Explain: 
        1. Update the maximum distance that can be covered in the next step.
                max(nums[1] + 1 = 4, nextCoverDistance = 2)
                                 0 1 2 3 4
        nums =                  [2,3,1,1,4]
                                   -------
        nextCoverDistance = 4

        2. Determine the minimum distance for the current step.
            if i != curCoverDistance

    3rd:            
                             0 1 2 3 4
    nums =                  [2,3,1,1,4]
    i = 2                        ^
    nums[2] = 1
    curCoverDistance = 2;
    recordStep = 1;
    nextCoverDistance = 4;

        Explain: 
        1. Update the maximum distance that can be covered in the next step.
                max(nums[2] + 2 = 3, nextCoverDistance = 4)
                                 0 1 2 3 4
        nums =                  [2,3,1,1,4]
                                   -------
        nextCoverDistance = 4
        2. Determine the minimum distance for the current step.
            if i == curCoverDistance
                recordStep ++;
        
        recordStep = 2;

        3. Update the index of the current maximum distance.
            curCoverDistance = nextCoverDistance;
        curCoverDistance = 4

        4. Check if the maximum distance has been reached, and if the endpoint is reached, stop immediately. 
            --> Reaching the endpoint, stop!      

*/



int jump(int* nums, int numsSize){

    if(numsSize < 2) return 0;

    int curCoverDistance = 0;
    int recordStep = 0;
    int nextCoverDistance = 0;

    for(int i = 0; i < numsSize; i ++){
        
        //Update the next step's maximum coverage distance
        nextCoverDistance = max(nextCoverDistance, nums[i] + i);
        
        //When reaching the current maximum coverage index (when the index equals the current maximum coverage distance, increment the step count by 1).
        if(i == curCoverDistance){
            recordStep ++;

            //If the index is updated, update the current coverage distance (update using the maximum coverage distance for the next step).
            curCoverDistance = nextCoverDistance;
            
            //If the next step's maximum coverage distance reaches the endpoint, stop!
            if(nextCoverDistance >= numsSize - 1) break;
        }
    }
    return recordStep;
}
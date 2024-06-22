#include <stdio.h>



void bubbleSort(int* nums, int numsSize);

int main(){

    int nums[] = {4,2,1,7,8};
    int numsSize = 5;

    bubbleSort(nums, numsSize);

    for(int k = 0; k <  numsSize; k ++){
        printf("%d\n", nums[k]);
    }
    
    return 0;
}



/*
    1st:
    
        1st:
            nums    =   [4,2,1,7,8]
                         ^ 
                           ^
            Explain: 
                Because of `4 > 2`, it need switch.

            nums    =   [2,4,1,7,8]
        
        2nd:
            nums    =   [2,4,1,7,8]
                           ^ 
                            ^
                Because of `4 > 1`, it need switch.

            nums    =   [2,1,4,7,8]

        3rd:
            nums    =   [2,1,4,7,8]
                             ^ 
                               ^
            Explain: 
                Because of `4 < 7`, don't need to switch.

        4th:
            nums    =   [2,1,4,7,8]
                               ^ 
                                 ^
            Explain: 
                Because of `7 < 8`, don't need to switch.

    As you can see the first round, we have already find out the largest number in the right side.
    
    2nd: 
        1st:
            nums    =   [2,1,4,7,8]
                         ^ 
                           ^
            Explain: 
                Because of `2 > 1`, it need switch.

            nums    =   [1,2,4,7,8]

        2nd:
            nums    =   [1,2,4,7,8]
                           ^ 
                             ^
            Explain: 
                Because of `2 < 4`, don't need to switch.

        3rd:
            nums    =   [1,2,4,7,8]
                             ^ 
                               ^
            Explain: 
                Because of `4 < 7`, don't need to switch.


        4th:
            nums    =   [1,2,4,7,8]
                               ^ 
                                 ^
            Explain: 
                Because of `7 < 8`, don't need to switch.

    3rd:
        1st:
            nums    =   [1,2,4,7,8]
                         ^ 
                           ^
            Explain: 
                Because of `1 < 2`, don't need to switch.
        2nd:
            nums    =   [1,2,4,7,8]
                           ^ 
                             ^
            Explain: 
                Because of `2 < 4`, don't need to switch.
        3rd:
            nums    =   [1,2,4,7,8]
                             ^ 
                               ^
            Explain: 
                Because of `4 < 7`, don't need to switch.
        4th:
            nums    =   [1,2,4,7,8]
                               ^ 
                                 ^
            Explain: 
                Because of `7 < 8`, don't need to switch.        

    4th:
        1st:
            nums    =   [1,2,4,7,8]
                         ^ 
                           ^
            Explain: 
                Because of `1 < 2`, don't need to switch.
        2nd:
            nums    =   [1,2,4,7,8]
                           ^ 
                             ^
            Explain: 
                Because of `2 < 4`, don't need to switch.
        3rd:
            nums    =   [1,2,4,7,8]
                             ^ 
                               ^
            Explain: 
                Because of `4 < 7`, don't need to switch.
        4th:
            nums    =   [1,2,4,7,8]
                               ^ 
                                 ^
            Explain: 
                Because of `7 < 8`, don't need to switch.      

    [Optimize]:
 
    As you can see, the biggest one has already on the right side, 
    however, each time, we still loop to the right. So, how can we optimize the algorithm?
    
    [Answer]:

    1. By reducing the inner loop by 1 after each completion (according to the outer loop).
    2. Because we don't need to compare the last one element, so we can set the loop assumption like this:
    
                `i < numsSize - 1`


*/


void bubbleSort(int* nums, int numsSize){
    for(int i = 0; i < numsSize - 1; i ++){
        for(int j = 0; j < numsSize - i - 1; j ++){
            if(nums[j] > nums[j + 1]){
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
#include<stdio.h>
#include<stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize);

int main(){
    int nums[] = {-4, -1, 0, 3, 10};
    sortedSquares(nums, 5, nums);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize){

    // return result
    int* result = (int*)malloc(numsSize * sizeof(int));
    int index = numsSize - 1;

    //Double Pointers
    int left = 0;
    int right = numsSize - 1;

    //Run the Results
    while(left <= right) {
        if(nums[left] * nums[left] > nums[right] * nums[right]) {
            result[index] = nums[left] * nums[left];
            left++;
        } else {
            result[index] = nums[right] * nums[right];
            right--;
        }
        index--;
    }

    *returnSize = numsSize;

    return result;
}

/*
    [Thought]:
    
    1st:
    1. Squares of each number
    2. Sorted the array
    --> I use the bubble sort but to be honest, the time complexity is not good enough.

    [Code]:
    int* sortedSquares(int* nums, int numsSize, int* returnSize){

        //Allocate memory for the result array
        int* result = (int*)malloc(numsSize * sizeof(int));
        if(result == NULL){
            printf("Memory Allocation Failed\n");
            exit(1);
        }

        
        //Step_01: Squares of each number
        for(int i = 0; i < numsSize; i ++){
            result[i] = nums[i] * nums[i];
        }

        //Step_02: Sorted the Array
        //Bubble Sort
        for(int i = 0; i < numsSize - 1; i ++){
            for(int j = 0; j <  numsSize - i - 1; j ++){
                if(result[j] > result[j + 1]){
                    int temp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = temp;
                }
            }
        }

        // Set the returnSize to the size of the result array
        *returnSize = numsSize;

        return result;
    }

    [Key Point]
    1. Review `Bubble Sort`.

    2nd:
    The array is actually, sorted, but squaring the negative numbers may turn them into the largest values.
    Thus, the maximum value of the squared array will be at the ends of the array, either on the far left or the far right,
    and it cannot be in the middle.

    [Code]:
    int* sortedSquares(int* nums, int numsSize, int* returnSize){

        // return result
        int* result = (int*)malloc(numsSize * sizeof(int));
        int index = numsSize - 1;

        //Double Pointers
        int left = 0;
        int right = numsSize - 1;

        //Run the Results
        while(left <= right) {
            if(nums[left] * nums[left] > nums[right] * nums[right]) {
                result[index] = nums[left] * nums[left];
                left++;
            } else {
                result[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }

        *returnSize = numsSize;

        return result;
    }
*/
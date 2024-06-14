#include <stdio.h>

int search(int* nums, int numsSize, int target);

int main(){
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int numsSize = 6;
    int target = 9;
    search(nums, numsSize, target);
}


int search(int* nums, int numsSize, int target){

    int right = numsSize - 1;
    int left = 0;
    while(left <= right){
        int middle = (left + right) / 2;
        if(target > nums[middle]){
            left = middle + 1;
        }
        if(target < nums[middle]){
            right = middle - 1;
        }
        if(target == nums[middle]){
            printf("%d", middle);
            return middle;
        }
    }
    printf("-1\n");
    return -1;

}


/*
    [Thought]
    1. I didn't do well for the first time because I misunderstood the problem statement.
    --> The statement of the problem is to find the target number, not two sum.

    1st:
    int search(int* nums, int numsSize, int target){

        if(numsSize == 1){
            if(target == nums[0]){
                printf("0\n");
                return 0;
            }else{
                printf("-1\n");
                return -1;
            }
        }

        for(int i = 0; i < numsSize; i++){
            for(int j = i + 1; j < numsSize; j ++){
                if(target == nums[i + 1] + nums[j]){
                    printf("%d\n", j);
                    return j;
                }
            }
        }
        printf("-1\n");
        return -1;
    }


    2. Because of finding the target, we could only loop to find the target.

    2nd:
    int search(int* nums, int numsSize, int target){

        for(int i = 0; i < numsSize; i++){
            if(nums[i] == target){
                printf("%d\n", i);
                return i;
            }
        }
        printf("-1\n");
        return -1;

    }

    However, the efficiency is not good enough. 
    Time Complexity O(n)
    Space Complexity O(1)


    3. [Key Words]

        The premise of this problem is that the array is sorted, and it also emphasizes that there are no duplicate elements in the array.

        --> Sorted Array(Ascending/ Descending) + No Duplicate
            ---> Binary Search

    3rd:
    int search(int* nums, int numsSize, int target){

        int right = numsSize - 1;
        int left = 0;
        while(left <= right){
            int middle = (left + right) / 2;
            if(target > nums[middle]){
                left = middle + 1;
            }
            if(target < nums[middle]){
                right = middle - 1;
            }
            if(target == nums[middle]){
                printf("%d", middle);
                return middle;
            }
        }
        printf("-1\n");
        return -1;

    }

    Above code, there are some important concepts, we need to watch out.

        1. Avoiding integer overflow when calculating the variable middle.
        --> This can occur in dealing with very large numbers.

            [Origin]:
            middle = left + right / 2;
            [Improved]:
            middle = left + (right - left) / 2;

            - (left + right) / 2
                This approach can lead to overflow when both left and right are very large values. 
                If the sum of left and right exceeds the range that can be represented by an integer, it results in overflow. 
                For example, in C++, if left and right are close to INT_MAX (the maximum value for an integer), their sum can exceed INT_MAX, leading to undefined behavior.

            - left + ((right - left) / 2)
                This approach avoids the overflow issue. Since right - left will not exceed the range of either right or left


        2. Binary Search Key Point - Interval Problem 
            Above the question, we define the target within a left-closed and right-closed interval, i.e., [right, left] 

            --> So, the loop assumption should be (left <= right) since left == right is meaningful, so <= is used.
                If `nums[middle] > target`, set `right` to `middle - 1` because the current `nums[middle]` is definitely not the target, 
                and therefore, the right boundary of the next search interval should be `middle - 1`.

*/
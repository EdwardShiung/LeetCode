#include <stdio.h>


void rotate(int* nums, int numsSize, int k);
void reverse(int* nums, int firstElement, int lastElement);


int main(){
    int nums[] = {1,2,3,4,5,6,7};
    int k = 3;
    int numsSize = 7;
    rotate(nums, numsSize, k);

    for(int i = 0; i < numsSize; i ++){
        printf("%d", nums[i]);
        printf("\n");
    }
    return 0;
}

/*
    The approach to this problem.

- First thought:

    nums = [1,2,3,4,5,6,7]
    k = 3
    newArray = []

    Explain: 
        1. Because of K = 3, each of elements in the nums will more 3 steps.
        2. In addition, we can separate two parts: one is latter part, and the other is front part.
    1st:
        nums = [1,2,3,4,5,6,7]
                    7
    2nd:
        nums = [1,2,3,4,5,6,7]
                  6 7
    3rd:
        nums = [1,2,3,4,5,6,7]
                5 6 7
    4th:
        nums = [1,2,3,4,5,6,7]
                      1 
    5th:
        nums = [1,2,3,4,5,6,7]
                      1 2
    6th:
        nums = [1,2,3,4,5,6,7]
                      1 2 3
    7th:
        nums = [1,2,3,4,5,6,7]
                      1 2 3 4

    --> Using a new Array to store the elements might be a good approach.
        However, it will not follow the requirements.
        The requirement of space complexity is O(1).
        Upper method will be O(n) for space complexity.

- Second thought:
    nums = [1,2,3,4,5,6,7]
    k = 3
    newArray = []

    Explain:
        1. Reverse all the elements
        2. Find the modulus. 
            (Sometimes K > numsSize, so we need to find the mod.)
        3. Reverse the first part of array.(By mod)
        4. Reverse the second part of array.(By mod)

    1st:
        nums = [1,2,3,4,5,6,7]
    -->        [7,6,5,4,3,2,1]

    2nd:
        numsSize % k =  7 % 3 = 3

    3rd:
                0 1 2 3 4 5 6
        nums = [7,6,5,4,3,2,1]
               [5,6,7,4,3,2,1]

    4th:
                0 1 2 3 4 5 6
        nums = [7,6,5,4,3,2,1]
               [5,6,7,1,2,3,4]

    --> Using this approach is better way to meet the requirements (Space Complexity O(n)).                          
*/

void rotate(int* nums, int numsSize, int k){

    // 1st Step: Reverse all the elements
    reverse(nums, 0, numsSize - 1);

    // 2nd Step: Find the modulus.
    k = k % numsSize;

    // 3th Step: Reverse the first part of array.(By mod)
    reverse(nums, 0, k - 1);

    // 4th Step: Reverse the second part of array.(By mod)
    reverse(nums, k, numsSize - 1);

}


/*
    Below is not right because it will exceed the index of array.   
    Example:
                0 1 2 3 4 5 6
        nums = [1,2,3,4,5,6,7]

        if i == 6 , 6 < numsSize, but i + 1 will out of the index.
*/

// void reverse(int* nums){
//     int temp = 0;
//     for(int i = 0; i < sizeof(nums); i ++){
//         if(nums[i + 1]> nums[i]){
//             temp = nums[i];
//             nums[i] = nums[i + 1];
//             nums[i + 1] = temp;
//         }
//     }
//     for(int i = 0; i < sizeof(nums); i ++){
//         printf("%d",nums[i]);
//         printf("\n");
//     }
// }


/*
So, as you can see, it will not reverse the array.

        1 0
        2 1
        3 2
        4 3
        5 4
*/

/*
             0 1 2 3 4 5   
            [1,2,3,4,5,6]
             ^ ^
             2 1 3 4 5 6
               ^ ^
             2 3 1 4 5 6
                 ^ ^
             2 3 4 1 5 6
                   ^ ^
             2 3 4 5 1 6
                     ^ ^
             2 3 4 5 6 1

*/

// void reverse(int* nums){
//     int temp = 0;
//     for(int i = 1; i < sizeof(nums); i ++){
//         if(nums[i]> nums[i - 1]){
//             temp = nums[i - 1];
//             nums[i - 1] = nums[i];
//             nums[i] = temp;
//         }
//     }
//     for(int i = 0; i < sizeof(nums); i ++){
//         printf("%d",nums[i]);
//         printf("\n");
//     }
// }


/*
    How about switch the first and last element?

    Example_01:

            [1,2,3,4,5,6]
             ^         ^
            [6,2 3 4 5 1]
               ^     ^
            [6,5,3,4,2,1]
                 ^ ^       --> if curr == last, stop
            [6,5,4 3,2,1]


    PS. In this problem, no matter which element is bigger,
        we need to switch their position because the goal is to change the order.
        so, we don't need to care about the element, we only care about the index.
*/


void reverse(int* nums, int firstIndex, int lastIndex){
    
    int temp = 0;
    while(firstIndex < lastIndex){

            temp = nums[firstIndex];
            nums[firstIndex] = nums[lastIndex];
            nums[lastIndex] = temp;

        firstIndex ++;
        lastIndex --;
    }
}
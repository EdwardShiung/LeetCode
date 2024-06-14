#include<stdio.h>

int removeDuplicates(int* nums, int numsSize);


int main(){

    int nums[] = {1,1,1,2,2,3};             //{1,1,2,2,3}  //5
    int numsSize = 6;
    removeDuplicates(nums, numsSize);

}

/*
    The approach to this problem.

    1st:
                            0 1 2 3 4 5
                    nums = [1,1,1,2,2,3] 
    index(2)                    ^
    i Pointer(2)                ^
    Pointer(index -2)(0)    ^      

        Explain: 
                The value of pointers are the same, so we don't need to adjust it.

    2nd:
                            0 1 2 3 4 5
                    nums = [1,1,1,2,2,3] 
    index(2)                    ^
    i Pointer(3)                  ^
    Pointer(index -2)(0)    ^        

            Explain:    
                    Compared value of Pointers, those are different. 
                    So, we have to update it.
                            nums[index] = nums[i]
                        
                                    0 1 2 3 4 5
                            nums = [1,1,2,2,2,3] 
            index(2)                    ^
            i Pointer(3)                  ^
            Pointer(index - 2)(0)   ^
            
            Explain:  
                    After storing it, index should move forward for one step.
                        index ++;

                                    0 1 2 3 4 5
                            nums = [1,1,2,2,2,3] 
            index(3)                      ^
            i Pointer(3)                  ^
            i Pointer(index - 2)(1)   ^

    3rd:
                            0 1 2 3 4 5
                    nums = [1,1,2,2,2,3] 
    index(3)                      ^
    i Pointer(4)                    ^
    i Pointer(index - 2)(1)   ^

            Explain:    
                    Compared value of Pointers, those are different.
                    So, we have to update it.
                            nums[index] = nums[i]

                                    0 1 2 3 4 5
                            nums = [1,1,2,2,2,3]
            index(3)                      ^
            i Pointer(4)                    ^
            i Pointer(index - 2)(1) ^

            Explain:  
                    After storing it, index should move forward for one step.
                        index ++;
                                    0 1 2 3 4 5
                            nums = [1,1,2,2,2,3]
            index(4)                        ^
            i Pointer(4)                    ^
            i Pointer(index - 2)(1)   ^
    
    4th:
                            0 1 2 3 4 5
                    nums = [1,1,2,2,2,3] 
    index(3)                        ^
    i Pointer(5)                      ^
    Pointer(index - 2)(1)     ^

            Explain:    
                    Compared value of Pointers, those are different. 
                    So, we have to update it.
                            nums[index] = nums[i]

                                    0 1 2 3 4 5
                            nums = [1,1,2,2,3,3]
            index(4)                        ^
            i Pointer(5)                      ^
            i Pointer(index - 2)(1)   ^
            
            Explain:  
                    After storing it, index should move forward for one step.
                        index ++;

                                    0 1 2 3 4 5
                            nums = [1,1,2,2,3,3]
            index(5)                          ^
            i Pointer(5)                      ^
            i Pointer(index - 2)(3)       ^

*/


int removeDuplicates(int* nums, int numsSize){
    
    if(numsSize <= 2) return numsSize;

    int index = 2;
    printf("%d", index);
    for(int i = 2; i < numsSize; i++){
        if(nums[i] != nums[index - 2]){
            nums[index] = nums[i];
            index ++;
            printf("%d", i);
        }
    }

    printf("%d", index);
    return index;
}




/*
[Thought]:

When the first time I did this question, I never thought about using one variable which could store the key changing element(index).
In addition, I never thought about the index starting point set index = 2, which could trace the elements easily.

[Key Point]:
1. The question give us an array which sorted in non-decreasing order, which means that allows us to track the count of element occurrences 
using a single variable. Therefore, one variable is sufficient to solve the problem.

2. However, if the question is an unsorted array, we have to use hashmap to record the occurrences.

[Related Questions]:
    1. Leetcode 26

*/


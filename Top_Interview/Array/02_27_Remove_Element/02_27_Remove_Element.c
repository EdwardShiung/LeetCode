#include<stdio.h>

//Declare removeElement
int removeElement(int* nums, int numsSize, int val);


int main(){

    int numArray[] = {3,2,2,3};
    int val = 3;
    removeElement(numArray, 4, val);

}

/*
    The approach to this problem.
            [3,2,2,3]
    Begin    ^
    End            ^

    1st     [3,2,2,_]
    Begin    ^
    End          ^     i --

    2nd     [2,2,_,_]
    Begin    ^ 
    End        ^        i --

    3rd     [2,2,_,_]
    Begin      ^
    End        ^
        --> Begin == End --> loop finish
        --> return tail + 1
*/

int removeElement(int* nums, int numsSize, int val){

    int slow = 0;
    for(int fast = 0; fast < numsSize; fast ++){
        if(nums[fast] !=  val){
            nums[slow] = nums[fast];
            slow ++;
        }
    }
    printf("%d", slow);
    return slow;
}   

/*
    [Thought]:
    1st:
        [Approach_01]: Double Pointers
        1. In the first time, use double pointers to complete the problem.
        2. set two different pointers
            - tail pointer      (Check the remaining array size)
            - beginning pointer
        
        once the beginning pointer find out the target number, 
            beginning pointer = tail
            tail --;

        so, the result is return the tail

        int removeElement(int* nums, int numsSize, int val){

            int tail = numsSize - 1;

            printf("%d", tail);
            printf("\n");

            int begin = 0;

            while(begin <= tail){
                if(nums[begin] == val){
                    nums[begin] = nums[tail];
                    tail --;
                }else{
                    begin ++;
                }
            }
            printf("%d", tail + 1);
            return tail + 1 ;
        }   
    
    2nd:
        [Approach_02]: Double Pointers
        2. set two different pointers
            fast (Find the target number)
            slow (Record the size of array)
        if find the target numer, slow will not move until the next round.


        int removeElement(int* nums, int numsSize, int val){

            int slow = 0;
            for(int fast = 0; fast < numsSize; fast ++){
                if(nums[fast] !=  val){
                    nums[slow] = nums[fast];
                    slow ++;
                }
            }
            printf("%d", slow);
            return slow;
        }   
*/
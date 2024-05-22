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


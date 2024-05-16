#include <stdio.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);


int main(){
    int numsArray_01[] = {1,2,3,0,0,0};
    int numsArray_02[] = {2,5,6};
    merge(numsArray_01, 6, 3, numsArray_02, 3, 3);
}


/*
    The approach to this problem
    1. Put all elements to the nums1 Array.
    2. Sorted elements 
        Ex: Bubble Sort

    - Before: 
        - Bubble Sort
             0 1 2 3 4 5 
        nums1 = [1,2,3,0,0,0] --> m = 3
                 ^
        nums2 = [2,5,6] --> n = 3
                 ^
    - After:
    [1,2,2,3,5,6]
*/


void merge(
        int* nums1, 
        int nums1Size, // nums1Size = m + n
        int m, 
        int* nums2, 
        int nums2Size, // nums2Size = n
        int n) {
        
        int i = m;
        int j = 0;
        int k = 0;
        //Step 1 : Put all of the elements into the nums1 Array.
        while(i != m + n){
            nums1[i] = nums2[j];
            i ++;
            j ++;
        }
        //Step 2 : Bubble Sort:
        for(int p = 0; p < m + n; p ++){
            for(int q = 0; q < m + n - p - 1; q ++){
                if(nums1[q] > nums1[q + 1]){
                    int temp = 0;
                    temp = nums1[q];
                    nums1[q] = nums1[q + 1];
                    nums1[q + 1] = temp;
                }
            }
        }

        //Verify
        int g = 0;
        while(g != (m + n)){
            printf("%d\n", nums1[g]);
            g ++;
        }
}
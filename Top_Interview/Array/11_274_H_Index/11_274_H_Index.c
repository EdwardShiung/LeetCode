#include <stdio.h>

int hIndex(int* citations, int citationsSize);


int main(){
    int citations[] = {1,3,1};
    int citationsSize = 3;

    hIndex(citations, citationsSize);
}


/*

Initially, I don't understand the problem. After reading the requirements several times, 
I realize that we need to determine the highest number of citations that meet the h-index criteria.

For example, given the array:

    [3, 0, 6, 1, 5]

First, we sort the array:
    
    [0, 1, 3, 5, 6]

Then, we can find that the author at least 3 papers with at least 3 citations each.

Thus, my approach as follows:
    1. Sort the array 
    2. Identify the highest value of h where the author has at least h papers with at least h citations each.

*/

int hIndex(int* citations, int citationsSize){

    //Special case: there is only one paper
    if(citationsSize == 1) return citations[0] == 0 ? 0 : 1;

    //Step01: Sort the Array
    int temp = 0;
    for(int i = 0; i < citationsSize - 1; i++){
        for(int j = 0; j < citationsSize - 1 - i; j++){
            if(citations[j] > citations[j + 1]){
                temp = citations[j];
                citations[j] = citations[j + 1];
                citations[j + 1] = temp;
            }
        }
    }

    //Step02: Identify the highest value
    int hIndex = 0;
    for(int i = 0; i < citationsSize; i++){
        int h = citationsSize - i;
        if(citations[i] >= h){
            hIndex = h;
            break;
        }
    }

    printf("%d", hIndex);
    return hIndex;

}



/*
    [Thought]

    1. Initially, when I identify the h-index, I find the middle index of the array, which is not right.

    For example:
        [0,1]
        --> If I find the middle of the array, it will get the h-index with 0;
    So, this is not correct.

    After I observe the relation of index and element location (sort array), I found a rule like this:
    
    Index        0  1  2  3  4
                [0, 1, 3, 5, 6]
    position     1  2  3  4  5

    If the number greater than or equal to than location, it could be a h-index. 
    Above that, 3 is the h-index.


    2. Bubble Sort Review

    3. The time complexity is O(n^2), which could be optimized in the future.

*/
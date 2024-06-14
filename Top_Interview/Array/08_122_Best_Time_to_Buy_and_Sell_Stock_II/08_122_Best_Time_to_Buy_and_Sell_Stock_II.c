#include <stdio.h>
#include <stdlib.h>



int maxProfit(int* prices, int pricesSize);



int main(){

    int prices[] = {7,1,4,3,1};
    int pricesSize = 5;

    maxProfit(prices, pricesSize);

}


/*
    The approach to this problem.
*/

//First Time to Write this code:
// int maxProfit(int* prices, int pricesSize){
    
//     //Step 1: Predict the Maximum Transaction
//     int maxTransaction = pricesSize * (pricesSize - 1) / 2;
//     //Step 2: Memory Allocation
//     int* profitArray = (int*)malloc(maxTransaction * sizeof(int));
//     int profitIndex = 0;
//     int maxProfit = 0;

//     for(int i = 0; i < pricesSize; i ++){
//         for(int j = i; j < pricesSize; j ++){
//             if(prices[j] - prices[i] > 0){
//                 profitArray[profitIndex] = prices[j] - prices[i];
//                 profitIndex ++;
//             }
//         }
//     }

//     for(int i = 0; i < sizeof(profitArray); i ++){
//         printf("%d\n", profitArray[i]);
//     }

//     for(int k = 0; k < sizeof(profitArray); k ++){
//         maxProfit += profitArray[k];
//     }
//     //Step 3: Release the Memory
//     free(profitArray);
//     printf("%d\n", maxProfit);
//     return maxProfit;

// }

//Second Time to write this code:
// int maxProfit(int* prices, int pricesSize){
    
//     //Step 1: Predict the Maximum Transaction
//     int maxTransaction = pricesSize * (pricesSize - 1) / 2;
//     //Step 2: Memory Allocation
//     int* profitArray = (int*)malloc(maxTransaction * sizeof(int));
//     int profitIndex = 0;
//     int maxProfit = 0;

//     for(int i = 0; i < pricesSize; i ++){
//         for(int j = i + 1; j < pricesSize; j ++){
//             if(prices[j] - prices[i] > 0){
//                 maxProfit += (prices[j] - prices[i]);
//             }
//         }
//     }
//     printf("%d\n", maxProfit);
//     return maxProfit;

// }

//Third Time to write this code:

int maxProfit(int* prices, int pricesSize){
    //Step 1 : Initialize the maxProfit
    int maxProfit = 0;


   //Step 2 :
    //If the price on a given day is lower than the previous day, sell it.
    /*--> Thus, instead of calculating (pairing) each element to find the maximum value,
          the formula is not suitable for use:
                        n (n - 1) / 2
    */

   for(int i = 1; i < pricesSize; i ++){
    if(prices[i] - prices[i - 1] > 0){
        maxProfit += prices[i] - prices[i - 1];
    }
   }

   printf("%d\n", maxProfit);
   return maxProfit;


}


/*
    [Thought]:

    1. I have to review:
        a. stdlib.h is very important library
        b. sizeof --> not always represent to an size of array; sometime it means size of pointer, it depend on. 
        b. malloc
        c. realloc
        d. what's segmentation fault  
        e. don't forget to release the memory which will been used
    
    2. For the first and second thoughts, I didn't figure out the problem which pairing is not suitable for this problem.
       In addition, if next time, I don't know what's size of array, we can use realloc.
       
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int* profitArray = NULL;
    int profitIndex = 0;
    int maxProfit = 0;

    // 動態增加數組大小
    for (int i = 0; i < pricesSize; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] - prices[i] > 0) {
                profitArray = realloc(profitArray, (profitIndex + 1) * sizeof(int));
                if (profitArray == NULL) {
                    fprintf(stderr, "內存分配失敗\n");
                    return -1;
                }
                profitArray[profitIndex] = prices[j] - prices[i];
                profitIndex++;
            }
        }
    }

    // 計算最大利潤
    for (int k = 0; k < profitIndex; k++) {
        maxProfit += profitArray[k];
    }

    printf("%d\n", maxProfit);
    free(profitArray);  // 記得釋放動態分配的內存
    return maxProfit;
}

*/
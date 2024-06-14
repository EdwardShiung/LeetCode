#include <stdio.h>

int maxProfit(int* prices, int pricesSize);


int main(){

    int prices[] = {7,6,4,3,1};
    int pricesSize = 5;
    maxProfit(prices, pricesSize);

}

/*
First Approach:
    Time Limit Exceeded because the time complexity is O(n^2).
*/

// int maxProfit(int* prices, int pricesSize){

//      int flag = 0;
//      for(int i = 0; i < pricesSize; i ++){
//         for(int j = i + 1; j < pricesSize; j ++){
//             flag = flag > (prices[j] - prices[i]) ? flag : (prices[j] - prices[i]);
//         }
//      }

//      if(flag > 0){
//         printf("%d", flag);
//         return flag;
//      }else{
//         printf("0");
//         return 0;
//      }
     
// }

/*
Second Approach:
    For using the below approach, it only cause time complexity O(n).    
*/

int maxProfit(int* prices, int pricesSize){

    //Basic: if pricesSize less than 2, it only return 0;
    if(pricesSize < 2) return 0;

    //Initial Price: Suppose that price[0] is the lowest price.
    int minPrice = prices[0];
    //Max Profit: Suppose that maxProfit is 0;
    int maxProfit = 0;

    for(int i = 1; i < pricesSize; i ++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        if(prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
        }
    }
    printf("%d", maxProfit);
    return maxProfit;
}
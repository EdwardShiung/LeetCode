#include <iostream>
#include <unordered_set>
using namespace std;


int getSum(int n) {
    int sum = 0;
    while(n) {
        // 取得個位數字的相乘
        sum += (n % 10) * (n % 10);
        // 取得十位數字
        n /= 10;
    }
    return sum;
}

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;

        while(1) {
            int sum = getSum(n);
            if(sum == 1) return true;
            // 判斷這個 sum 是否曾經出現在 set 陣列中
            // 如果曾經出現過，則代表進入無限迴圈了，此時，return false
            if(set.find(sum) != set.end()) {
                return false;
            }else{
                set.insert(sum);
            }
            n = sum;
        }
    }
};





int main() {
    

    
    return 0;
}
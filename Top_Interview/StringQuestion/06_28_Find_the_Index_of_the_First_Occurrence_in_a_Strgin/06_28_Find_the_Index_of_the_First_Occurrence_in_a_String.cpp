#include <iostream>
using namespace std;

/*
本題：兩步驟

        Ex:
        S1: aabaabaaf
        S2: aabaabf

1. 找到 next 陣列

        前綴表表示方法總共有三種

        以 aabaaf 為例：
        
        1. 正常來看，其前綴表 next 為：
        {0, 1, 0, 1, 2, 0}
        
        --> 當兩字串比較，發生不一時，請查看前一位對應的 next 值
        --> next 查出的值，為跳到模式串下標值，進行比對

        2. 如果是以，往右移一位
        {-1, 0, 1, 0, 1, 2}

        --> 當兩字串比較，發生不一時，請查看當前位置 next 值
        --> next 查出的值，為跳到模式串下標值，進行比對

        3. 如果是同時減去 1
        {-1, 0, -1, 0, 1, -1}

        --> 當兩字串比較，發生不一時，請查看下標前一位，並且 
        --> 當兩字串比較，發生不一時，請查看前一位對應的 next 值
        --> next 查出的值，"請加上 1"，並跳到模式串下標值，進行比對

2. 透過next，進行 S1 和 S2 比對

    --> 因為已經得到了 next 陣列，可以直接使用 next 陣列與 S1 比對。

*/


class Solution {

public:
    // 第一部分：找到 next 陣列
    void getNext(int* next, const string& s){
        /*
            1. 這部分，本質上也是透過雙指針( j 在前; i 在後)
            2. 由於 j 初始值為 -1(假定第一個下標為 -1，因為不存在前綴)，所以記得使用 j 指定字串下標時， j + 1。
            3. [思路]:
                Step_1: 初始化
                Step_2: 前後綴不相同情況
                Step_3: 前後綴相同情況
                Step_4: 更新 next 陣列
            4.  i 指向後綴末尾
                j 指向前綴末尾
                    --> j 也同時代表 包含 i 之前的最長相等前後綴長度
        */
        // Step_01 Initialize the first index of string
        int j = -1;
        next[0] = j;
        
        // i 和 j 進行比較
        // i 從 index = 1 開始
        for(int i = 1; i < s.size(); i++) {
            // j 從要記得從 index = j + 1 開始
            // 當 j 和 i 下標所反應的前後綴不同時
            // [注意]：這裡不能寫 "if"。因為，當發生不一樣的時候，是連續回退
            while(j >= 0 && s[j + 1] != s[i]) {
                // --> 當兩字串比較，發生不一時，請查看下標前一位，並且 
                j = next[j];
            }
            // if s[j + 1] 前綴，和後綴 s[i] 相同時，j 往前動
            if(s[j + 1] == s[i]) {
                j++;
            }
            // 每次判斷每一個下標，都同時給予最長相等前後綴長度
                //j 指向前綴末尾
                  //  --> j 也同時代表 包含 i 之前的最長相等前後綴長度
            next[i] = j;
        }
    }
    // 第二部分：進行 S1 和 Ｓ2比對
    int strStr(string haystack, string needle) {
        
        // 用 next 陣列存放值
        int nextSize = needle.size();
        int* next = new int[nextSize];
        
        // 透過第一部分：得到next
        getNext(next, needle);
        
        // next index 下標 k (因為尋找 next 方法時，使用全部減 1 法，所以當不匹配時，往前一個下標查看next值)
        int k = -1;

        // S1 與 S2 進行比對
        for(int i = 0; i < haystack.size(); i++) {
            // 當 兩字串不匹配時
            while(k >= 0 && haystack[i] != needle[k + 1]) {
                k = next[k];
            }
            // 當 兩字串匹配時
            if(haystack[i] == needle[k + 1]) k++;

            // 當匹配到最後一個值時：代表 S1 中，有找到 S2 字串
            if(k == (needle.size() - 1)) return (i - needle.size() + 1);
        }


        // 如果比對都沒有找到，return -1
        return -1;
    }
};

int main() {
    
    Solution solution;

    string haystack = "leetcode";
    string needle = "aabaaf";
    int nextSize = needle.size();
    int* next = new int[nextSize];

    solution.getNext(next, needle);

    for(int i = 0; i < nextSize; i++) {
        cout << next[i] << " ";
    }

    cout << endl;
    return 0;
}



/*
[後記一]：

在 C++ 中，建議使用 new 和 delete 來分配和釋放記憶體，而不是使用 C 語言中的 malloc 和 free。原因有以下幾點：

1.new 和 delete 是 C++ 的運算符，而 malloc 和 free 是 C 語言的函數。new 和 delete 會自動調用對象的建構函數和解構函數，而 malloc 和 free 不會。

2.new 和 delete 提供了更好的型別安全。new 會返回正確的指針類型，不需要類型轉換，而 malloc 返回的是 void*，需要手動轉換。

3.new 可以用於分配任何數據類型，包括數組，而 malloc 主要用於分配記憶體。

4. 使用 new 和 delete 可以避免一些常見的錯誤，如忘記分配或釋放記憶體，或者分配和釋放記憶體的大小不匹配。

[後記二]：

1. vector 生成的陣列，和 new 生成的陣列差異要去了解！！


*/
#include <iostream>
#include <deque>
using namespace std;

/*
    [Question]

    You are given an array of integers nums, 
    there is a sliding window of size k which is moving from the very left of the array to the very right. 
    You can only see the k numbers in the window. 
    Each time the sliding window moves right by one position.
    Return the max sliding window.
*/
/*
    [Thought]

    Ex: 
    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]

    Window position                Max
    -------------------------    -----
    [1  3  -1] -3  5  3  6  7      3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7

    1. 本題不能使用優先級隊列 Priority Queue （又稱大頂堆 Heap 方法）
        --> 本題如果使用優先級隊列，以上述為例子：
        [3, 1, -1]，此時要 pop 出去 1，無法立刻 pop 出去
        --> 這種方式類似 Binary Tree 的方式，這樣元素刪除和進出較為困難。

    2. 只能使用 “單調隊列” Monotonic Queue:
        --> 如何加上元素
        --> 如何去掉元素
            --> 單調隊列可以自定義 
                --> 本題 隊列 使用 deque 底層容器實現。( 重點：左右兩邊可以出、入元素 )
                --> 本題思路：只需要將有可能的最大值，放入隊列中，並且出口處，維持最大值。
                    --> Push: 進來的元素，比前面都大，則元素由後端彈出 pop_back() 
                                --> 這邊使用 pop_back()
                                    --> 會彈出所有在隊列裡的數值
                                --> 全部彈出後，才加入新的數值
                                    Ex:
                                        隊列中已經有：
                                        front <-- 5,2,1,0  --> back
                                        現在要加入 3
                                        則 pop_back()，彈出 0, 1, 2
                                            --> 使用 while 迴圈去判斷隊列裡的值 vs 新加入的值，哪個大
                        --> 如果放進來比前面都小，就可以安心的放進去 
                    --> Pop: 當要彈出的值，與對列出口（front）的值相同時，則彈出
                            --> 同時，判斷是否為空
                    --> getMaxValue: 其實就是 front

        PS.
        deque 容器產生的”單調隊列“，其功能
        --> pop()
        --> push()
        --> empty()
        --> front()
        --> back()
        --> pop_front()
        --> pop_back()
*/



class Solution {
private:
    class MyQueue {
    public:
        // 創建 deque 實踐 queue 
        deque<int> queue;

        // pop 彈出數據：
        /*
            1.每次彈出時，比較當前要彈出的值，是否與對列出口相等，相等則彈出。
            2.彈出前，請判斷隊列是否為空
        */
       void pop(int value) {
        if(!queue.empty() && value == queue.front()) {
            queue.pop_front();
        }
       }
        //push 加入數據：
        /*
            1. 如果 push 的值 ，從後端加入，發現都比前面的大，則先由後端彈出元素，再加入新元素。
            2. 保持隊列由大到小排列（front為最大）
        */
       void push(int value) {
        while(!queue.empty() && value > queue.back()) {
            queue.pop_back();
        }
        queue.push_back(value);
       }

       // getMaxValue: 因為放進去時，已經排序過，所以就是 front 最大
        int front() {
            return queue.front();
        }
      
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 使用 MyQueue
        MyQueue que;
        // 創建 results 陣列
        vector<int> results;
        // 先將 資料輸入到 Queue 中，但是，“只輸入前面 k”
        for(int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        // 記錄前 k 個最大值
        results.push_back(que.front());
        // 接著，每次挪動一個下標 (三個三個比較)
        for(int i = k; i < nums.size(); i++) {
            // 滑動時，移除最前面的元素
            que.pop(nums[i - k]);
            // 滑動時，由後，加入元素
            que.push(nums[i]);
            // 紀錄最大值
            results.push_back(que.front());
        }
        return results;
    }
};


int main() {


    return 0;
}
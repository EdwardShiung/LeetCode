#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;
/*
    [Question]
    Given an integer array nums and an integer k, 
    return the k most frequent elements. 
    You may return the answer in any order.

        Example 1:

        Input: nums = [1,1,1,2,2,3], k = 2
        Output: [1,2]
        Example 2:

        Input: nums = [1], k = 1
        Output: [1]
        

        Constraints:

        1 <= nums.length <= 105
        -104 <= nums[i] <= 104
        k is in the range [1, the number of unique elements in the array].
        It is guaranteed that the answer is unique.

    [Thought]
    1.  [錯誤思維]
            --> 本題第一次看題目，以為是給定一個陣列 nums 和 數值 k，並返回 數值 K 中，在陣列出現幾次。
                --> 但實際上不是！！請看清楚題目！！
        [正確思維]
            --> 在陣列中，要找到頻率出現次數前 k 高的值
            
            Ex_01:
            nums = [1,1,1,2,2,3], k = 2
            1 有 3次
            2 有 2次
            3 有 1次
            --> 返回頻率出現次數前 2 高的值
            --> [1,2]

            Ex_02:
            nums = [4,4,4,3,3,2,1], k = 3
            4 有 3次
            3 有 2次 
            2 有 1次
            1 有 1次
            --> 返回頻率出現次數前 3 高的值 
            --> [4,3,2] 或 [4,3,1]
    
    2. 第一時間，想到使用 map，因為可以紀錄 key 和 value。這裡的 key 為陣列元素，value 統計次數。

    3. 利用 Priority Heap 來解決此問題。
        --> 了解大小頂堆，時間複雜度 O(nlogn)
                --> 此種情況，尤其在 "數據集合量大" 時且 "k 很小" 時，其時間複雜度性能是最好的。
                --> 每次考慮新的元素加入 Heap，時間複雜度只增加 logn
            --> 大頂堆: 根節點 > 左、右子節點
            --> 小頂堆: 根節點 < 左、右子節點
                --> 堆 (Heap) 底層實現，為“二叉樹 Binary Tree”
        --> 暴力解法容易造成 Time Complexity 超時。

    [Review]
    1. 實踐大頂堆、小頂堆
    2. Review Hash Method 利用 C++ 使用 map
    3. 本題很多觀念，可以看出 C++ 熟悉度
        --> a. STL 基本容器
            --> vector、map、set、pair 等基本容器的使用
        --> b. STL 容器適配器
            --> priority_queue 等容器適配器的使用
                --> ex: 什麼是容器適配器 Container Adapter?
        --> c. 運算符重載和函數對象
            --> 如何創建自定義比較函數
        --> d. 模板編程
            --> 類模板和函數模板的使用
            --> 類 和 結構體的差異
        --> e. 數據結構和算法
            --> 堆和優先隊列的基本概念和應用
            --> 小頂堆實踐
            --> 大頂堆實踐
*/


class Solution {
public:
    // 比較（形成小頂堆）
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 統計元素出現頻率
        unordered_map<int, int> map; 
        // map<nums[i],統計元素對應的頻率>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        // 對頻率的排序
        // 定義一個小頂堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        
        // 用固定大小為 K 的小頂堆，掃描所有頻率數值
        // 這是 map 寫法 unordered_map<int, int>::iterator it 
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            // 如果堆的大小大餘 K，則彈出隊列：保證堆的大小一直為 K
            if (pri_que.size() > k) { 
                pri_que.pop();
            }
        }
        // 找出前 K 個高頻元素：小頂堆會最先彈出最小的，所以倒續，所以"倒序"輸出到陣列。
        // 定義一個要返回的陣列 result
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};


/*

這部分主要解釋 Priority Queue 容器適配器寫法。
將這個部分： 
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
分解為以下步驟：

    // 定義 pair<int, int> 類型
    typedef pair<int, int> Element;

    // 自定義比較函數，用於 priority_queue
    struct mycomparison {
        bool operator()(const Element& lhs, const Element& rhs) const {
            return lhs.second > rhs.second;  // 比較元素的頻率
        }
    };

    // 定義底層容器類型
    typedef vector<Element> Container;

    // 定義優先隊列類型
    typedef priority_queue<Element, Container, mycomparison> PriorityQueue;
*/

int main() {
    
    
    return 0;
}
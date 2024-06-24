#include <iostream>
#include <vector>
using namespace std;

/*
    何時用哈西法？
    ANS: 在一個集合裡面判斷是否有出現的元素。

    此題為何可以使用哈西法？
    ANS: 與 LeetCode 15 三數之和、LeetCode 18 四數之和 不同：
        - 本題給予四組陣列
        - 只要找到 A[i] + B[j] + C[k] + D[l] = 0 就可以
        - 不用考慮重複的四個元素
    
    ** 難度提升：本題可以改為一個陣列中，在這裡找出四個元素相加為 0，答案中不可以包含重複的四元組。
    --> LeetCode 18
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        // 四個數相加要為 0 
        /*
            前面 nums1 & nums2 兩兩相加產生的四個數字 要等於
                nums3 & nums4 兩兩相加產生的四個數字 的負數
            --> (a+b) = -(c+d)
            --> a + b + c + d = 0;
        */
        int count = 0;
        
        // 利用 unordered_map 去統計:
        // Key: a + b 的值; value: a + b 的次數
        unordered_map<int, int> umap;
        
        // 計算 nums1 和 nums2 所有元素相加，並且記錄 hashmap，每次相加出現的元素 + 1
        for(int a: nums1) {
            for(int b: nums2) {
                umap[a+b]++;
            }
        }
        // 計算 nums3 和 nums4 所有元素相加
        for(int c : nums3) {
            for(int d: nums4) {
                if(umap.find(0 - (c+d)) != umap.end()) {
                    count += umap[0 - (c+d)];
                }
            }
        }

        cout << count << " ";
        return count;

    }
};


int main() {

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};

    Solution sol;
    sol.fourSumCount(nums1, nums2, nums3, nums4);

    cout << endl;

    for(int a : nums1) {
        for(int b : nums2) {
            cout << a << b << "=" << a + b << " ";
        }
        cout << endl;
    }
}
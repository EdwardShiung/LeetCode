#include <iostream>
#include <vector>
using namespace std;


/*
    1. LeetCode 題型中，多數和求解，可分為：
        - LeetCode_01   2 Sum       --> Hash Method                     --> 沒有“去重”問題
        - LeetCode_15   3 Sum       --> Double Pointer + Loop Pointer   --> 三指標，皆有“去重”問題
        - LeetCode_18   4 Sum       --> Double Pointer + Loop Pointer   --> 皆有“去重”問題
        - LeetCode_454  4 Sum II    --> Hash Method                     --> 沒有“去重”問題，題目提供四組陣列
    --> 共性：皆有 target value

    2. 須了解”去重“邏輯
        本題三數之和: 
            a   +   b   +   c       =   0
            i   +  left +  right    =   0
        - a：去重邏輯，需了解是使用:
            - nums[i] == nums[i + 1]
                --> ex: {-1,-1,2}, i = 1
                    --> nums[0] = -1, nums[1] = -1：
                    -   這種情況下，{-1,-1,2} 就會被遺忘掉，但是此組數據，是有必要的
            - nums[i] == nums[i - 1]
                --> ex: {-1,-1,2}, i = 1
                    --> nums[0] = -1, nums[-1]  = 沒有(此為舉例，正常來說，無法判斷 i < 0)
                    --> 這種方式，不會遺忘掉{-1,-1,2}！！
        
        -b (left) 和 c (right) 去重邏輯
            - b 是 left，就看 b 的下一位是否和 b 相同。假如相同 left ++;
            - c 是 right，就看 c 的前一位是否和 c 相同。假如相同 right --;

    3. 了解本題為何要先排序！！！！！！
        --> 排序的目的，在於判斷：
            --> 三數之和 > 0 
                -> right --
            --> 三數之和 < 0 
                --> left ++
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 用來保留結果
        vector<vector<int>> results;
        // 排序 (小到大)
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            // 假如 nums[i] > 0, 直接 return result;
            if(nums[i] > 0 ) return results;

            // 去重 a
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // a 通過（無重複）
            int left = i + 1;
            int right = nums.size() - 1;

            while(right > left) {
                
                // 如果 三數之和 > 0, right--
                if(nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                // 如果 三數之和 < 0, left++
                }else if(nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }else{

                    //找到答案：三數之和為 0
                    results.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    
                    // right 去重
                    while(right > left && nums[right] == nums[right - 1]) right--;
                    // left 去重
                    while(right > left && nums[left] == nums[left + 1]) left++;

                    // 找到對的答案時
                    left++;
                    right--;
                }
            }
        }
        return results;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);

    cout << "Results:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
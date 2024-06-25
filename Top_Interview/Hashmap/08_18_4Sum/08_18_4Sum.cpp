#include <iostream>
#include <vector> 
using namespace std;


/*

    1. 三數之和中， nums[i] > 0 ，可以進行判斷。
    --> Q:   為何這題不能用 nums[k] > target，進行判斷呢？
    -->ANS:  在我們慣性思維中，以排序好的正數序列中，兩數相加會越來越大。
             然而，本題 target 是使用者自動輸入的，因此，有可能是負數。
             Ex:
                    a + b + c + d = -10
                {-4.-3,-2.-1}. target = -10
        --> 所以，上面的例子中，如果只判斷 nums[k] > target
        --> 則，-4 > -10 break的情況下，就錯過了 {-4.-3,-2,-1} 的情況
    --> 因此，依舊可以進行判斷，但要有前提，就是，target 為正數



    2. 本題思路：雙迴圈
        {-4.-3,-2,-1,0,1,2,3,4} 
    i     ^
    k       ^
    left        ^
    right                    ^
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 用來保留結果
        vector<vector<int>> results;
        // 排序（小到大）
        sort(nums.begin(), nums.end());
        // 一層
        for(int i = 0; i < nums.size(); i++) {
            // 假設target為正數 (這條假設僅針對 target)
            if(nums[i] > target && nums[i] > 0) {
                return results;
            }
            // a 去重 （向後查看）
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            //二層
            for(int k = i + 1; k < nums.size(); k++) {
                // 假設 target 為正整數，並且，前面兩層相加，如果大於 target，並且，前面兩層相加，都大於 0，則略過
                if(nums[i] + nums[k] > 0 && nums[i] + nums[k] > target) {
                    break;
                }
                // b 去重
                if(k > i + 1 && nums[k] == nums[k - 1]) {
                    continue;
                }
                // 二層中，設立 left 和 right
                int left = k + 1;
                int right = nums.size() - 1;
                // 進入 left 和 right 判斷及 四數相加判斷
                while(right > left) {
                    //四數相加 > 0，則 right--;
                    if((long)nums[i] + nums[k] + nums[left] + nums[right] > target){
                        right--;
                            //四數相加 < 0，則 left++;
                    }else if ((long)nums[i] + nums[k] + nums[left] + nums[right] < target){
                        left++;
                    }else{
                            // 四數相加 == 0，先放到 results
                            results.push_back(vector<int>{nums[i], nums[k], nums[left], nums[right]});
                            // 這部分判斷 left 和 right 重複問題
                            while(right > left && nums[left] == nums[left + 1]) left++;
                            while(right > left && nums[right] == nums[right - 1]) right--;

                            // 如果沒有重複問題，並且已經找到對的答案，要再次找尋，則：
                            left++;
                            right--;
                    }
                }
            }
        }
        return results;
    }
};

int main() {
    // 使用 Solution Class
    Solution solution;
    // 創建一維陣列
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> results = solution.fourSum(nums, target);

    cout << "Results:" << endl;
    for(const auto& index: results) {
        cout << "[";
        for(int num: index){
            cout << num << " ";
        }
        cout << "]"<< endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& nums) {
    const int n = (int)nums.size();
    int prefix = 0, suffix = 0;
    
    // 遍历从第二个元素到最后一个元素
    for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[i - 1]) {
            // 如果当前温度比前一个温度低，说明我们需要进行前缀操作
            prefix += nums[i - 1] - nums[i];
        } else {
            // 否则，我们需要进行后缀操作
            suffix += nums[i] - nums[i - 1];
        }
    }
    
    // 最后返回 prefix + suffix 加上 nums[0] 的调整 (起始温度调整)
    return prefix + suffix + nums[0]; 
};

int main() {
    vector<int> nums{2, -2, -3, 1};
    int results = solve(nums);
    printf("%d", results);  // 打印结果
}
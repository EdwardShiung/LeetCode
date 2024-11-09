#include <iostream>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while(left <= right) {
            middle = (left + right) / 2;
            if(nums[middle] > target) right = middle - 1;
            if(nums[middle] < target) left = middle + 1;
            if(nums[middle] == target) return middle;
        }
        cout << right + 1 << endl;
        return right + 1;
    }
};

int main() {
    vector<int> nums = {1,3,5,6};
    Solution solution;
    int results = solution.searchInsert(nums, 7);
    cout << results << endl;
}

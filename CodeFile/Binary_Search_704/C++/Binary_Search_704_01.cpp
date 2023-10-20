//[1st]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //定義左右位置
        //區間定義包含左邊及右邊 ==> [left, right]
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int middle = (left + left) / 2;
            if(nums[middle] > target){
                right = middle - 1;
            }else if(nums[middle] < target){
                left = middle + 1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};
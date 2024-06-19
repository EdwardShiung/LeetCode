#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
    1.每當遇到哪個元素在某個集合中時，可以選擇用 Hashmap。
    2.因為要得到元素和下標，因此用 map (key, value)
    --> map 是用來存放遍歷過的元素

    Ex:         [2,7,3,6]
    1st: key = 2, value = 0
    2nd: key = 7, value = 1

    --> return {0,1}

    - C++ 三種 map
    map             : 底層紅黑數
    multi_map       : 底層紅黑數
    unordered_map   : 底層 Hashmap

    --> 本題使用 unordered_map
*/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create unordered_map <key, value>
        std::unordered_map <int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            // iterate the element and find the key whether is suitable for the target.
            auto iter = map.find(target - nums[i]);
            // iter 在 map 中找到了目標值
            if(iter != map.end()) {
                vector<int> result;
                // Second refers to the second element of a pair within an std::unordered_map data structure.
                result.push_back(iter->second);
                result.push_back(i);
                return result;
            }
            // If it doesn't find out the value and index, store the value and index in the map.
            map.insert(pair<int, int>(nums[i], i));
        };
        return vector<int>();
    };
};


int main() {
    return 0;
}
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
        unordered_map <int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            // iterate the element and find the key whether is suitable for the target.
            /*
                auto 關鍵字用來讓編譯器自動推斷變數的類型。這對於編寫更簡潔和靈活的代碼非常有用，尤其是當變數的類型很複雜或者不易一眼看出時。
                1. auto：讓編譯器自動推斷 iter 變數的類型。
                2. iter：變數名。
                3. map.find(target - nums[i])：在 map 中查找鍵為 target - nums[i] 的元素，並返回一個迭代器指向該元素。

                具體來說，如果 map 是一個 std::unordered_map 或 std::map，那麼 map.find 函數會返回一個指向 std::pair 的迭代器，
                其中 std::pair 的第一個元素是鍵，第二個元素是與該鍵相關聯的值。
                這個迭代器的類型可能比較複雜，因此使用 auto 來自動推斷類型是很方便的。

            */
            auto iter = map.find(target - nums[i]);
            /*
                map.find(target - nums[i]) 的返回類型是 std::unordered_map<int, int>::iterator 的原因在於 find 方法在 C++ 的標準庫容器（例如 std::unordered_map 或 std::map）中返回一個迭代器。

                - std::unordered_map 和 std::map 都提供了 find 方法來查找容器中是否存在某個鍵。
                - find 方法返回一個迭代器，這個迭代器指向鍵值對（std::pair<const Key, T>），其中 Key 是鍵的類型，T 是值的類型。

                當我們調用 map.find(target - nums[i]) 時，find 方法會返回一個迭代器，其類型是 std::unordered_map<int, int>::iterator。

                這個迭代器是指向一個 std::pair<const int, int> 的迭代器，其中第一個元素是鍵（const int），第二個元素是值（int）。

                使用 auto 來自動推斷這個迭代器的類型，可以讓代碼更簡潔，不需要手動指定長而複雜的類型。
            */
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

    // Create some vector

    Solution sol;
    return 0;
}
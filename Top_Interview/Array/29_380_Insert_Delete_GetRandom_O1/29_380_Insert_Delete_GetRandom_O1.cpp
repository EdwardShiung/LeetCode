#include <iostream>
using namespace std;

/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 

Constraints:

-231 <= val <= 231 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.

*/


class RandomizedSet {
    // Store the value and index
    unordered_map<int, int> numsSchema;
    // Using the Array to store value 
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // detect the value in the hashmap 
        if(numsSchema.count(val)) return false;
        
        // Insert the value
        numsSchema[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        // detect the value in the hashmap 
        if(!numsSchema.count(val)) return false;

        //將要刪除的元素，與最後一個在Array 的值做交換
        // 取得 Array 中最後一個值
        int lastValue = nums.back();
        // 取得要刪除元素的 index
        int indexVale = numsSchema[val];

        // 將最後一個值，覆蓋到要刪除的值index位置
        nums[indexVale] = lastValue;

        // 更新 map 的 index （舊的值已經變成原先最後一個值）
        numsSchema[lastValue] = indexVale;

        // 刪除 nums 最後一個值
        nums.pop_back();

        //刪除 map 上, val 的值
        numsSchema.erase(val);

        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

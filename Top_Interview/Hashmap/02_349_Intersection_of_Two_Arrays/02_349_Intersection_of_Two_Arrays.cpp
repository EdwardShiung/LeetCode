#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


/*
    The brutal force solution for this problem has a time complexity of O(n^2).
    In order to optimize the solution, I will use the hash method.

    Using an array as a hash table is also a good choice.
    For example, leetcode 242 Valid Anagram is a good choice.
    
    However, it's important to note that using an array for hashing is feasible 
    because the problem constraints limit the size of values.
*/

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            
            // Storing the results to unordered set
            unordered_set<int> result_set;
            
            // Transferring the array to unordered_set array
            unordered_set<int> nums1_set(nums1.begin(), nums1.end());

            /**
            在C++的標準模板庫(STL)中，集合(set)的end()方法返回的是一個指向集合尾後位置的迭代器，而不是集合中最後一個元素的迭代器。
             
            這個尾後位置是超出集合範圍的一個位置，用來表示集合結束。

            具體來說，當你調用 nums_set.find(num) 時，這個方法會返回一個指向找到的元素的迭代器。
            
            如果找不到該元素，則會返回 nums_set.end()。所以 nums_set.end() 並不是集合中最後一個元素的迭代器，而是集合範圍之外的一個特殊標記。

            因此，nums_set.find(num) != nums_set.end() 的意思是：

            如果 nums_set.find(num) 返回的迭代器不等於 nums_set.end()，說明在集合中找到了 num 這個元素。
            如果 nums_set.find(num) 返回的迭代器等於 nums_set.end()，說明在集合中沒有找到 num 這個元素。
            用這種方式來檢查元素是否存在於集合中是非常常見的做法。這樣可以有效地利用集合的查找特性來進行判斷。

            */

           for(int num : nums2) {
            if(nums1_set.find(num) != nums1_set.end()) {
                result_set.insert(num);
            }
           }

            // Convert the unordered set to vector
            vector<int> result(result_set.begin(), result_set.end());

            return result;

        }
};

#include <vector>

int main() {
    
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9,4,9,8,4};

    Solution sol;
    vector<int> results = sol.intersection(nums1, nums2);

    // Print the result (I've to review how to print a vector);
    for(int num : results) {
        cout << num << " ";
    }
    cout << endl;

}
'''
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

[Though]:
    - 本題已說明，兩個 nums 皆為 "sorted array"
        - 先合併 (方法一)：合併後無排序
        - 先排序（方法二）：兩邊各挑一個，小的先排
                - 方法二就屬於線性時間複雜度
        [總結]：這兩種方法，在資料集小的時候，方法一 O((m + n) log (m + n)) 較快，
               但是，一但資料量很大的時候，將造成時間複雜度成長較大，效率降低。

    1. 方法一： (Brute Force) Merge 兩個 Array，sorted 後，找出中間值
        此方法 "合併" 再 "排序":
        - TC = O((m + n) log(m + n))
        - m 為 nums1
        - n 為 nums2
        - SC = O(m + n)
        -> 其中， python sort() 方法時間複雜度 O(n log n)
            --> 使用 Timsort 混合排序 （詳細請看附檔案 python 系列）
    
    2. 方法二： Two Pointer Method
        - 兩邊各挑一個，小的先排
        - TC = O(m + n)
        - 此方法較為佳
        
    3. 方法三： Binary Search Method
    
'''

from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> int:
        
        # Get the information from two nums array
        length_01 = len(nums1)
        length_02 = len(nums2)
        
        # Merged Array
        merged_nums = []
        
        # Set the index for two nums array
        index_nums1 = 0
        index_nums2 = 0
        
        # Merge the two arrays using two pointers
        while index_nums1 < length_01 and index_nums2 < length_02:
            if nums1[index_nums1] < nums2[index_nums2]:
                merged_nums.append(nums1[index_nums1])
                index_nums1 += 1
            else:
                merged_nums.append()(nums2[index_nums2])
                index_nums2 += 1
        
        # [Not Necessary]        
        # If there are remaining elements in nums1
        while index_nums1 < length_01:
            merged_nums.append(nums1[index_nums1])
            index_nums1 += 1
        # If there are remaining elements in nums1
        while index_nums2 < length_02:
            merged_nums.append(nums2[index_nums2])
            index_nums2 += 1

        # Find the median
        length = length_01 + length_02
        
        if length % 2 == 1:
            mid = length // 2
            return merged_nums[mid]
        else:
            mid = length // 2
            return (merged_nums[mid - 1] + merged_nums[mid]) / 2
        
        
    
        
        
        
        
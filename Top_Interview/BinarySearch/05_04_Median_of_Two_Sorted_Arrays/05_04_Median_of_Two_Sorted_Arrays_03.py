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
    Example:
    index: 0  1  2  3  4  5
    num1:  3  5  8  9
    num2:  1  2  7  10 11 12
    
    num3:  1  2  3  5  7 | 8  9  10  11  12
    
    思路演變過程：
    num3: -->  num1 + num2 --> num1
    
        
    3. 方法三： Binary Search Method
     - https://www.youtube.com/watch?v=jrhovhkAsCs
     - http://blog.csdn.net/chen_xinjia/article/details/69258706
     
    Example:
    index: 0  1  2  3  4  5
    num1:  3  5  8  9           cut1: 左邊有幾個元素
    num2:  1  2  7  10 11 12    cut2: 右邊有幾個元素
    
    - 如何找到 cut1 和 cut2
       - 試想一下，合併後的 nums3，要在 nums3 找到中間值
           num3:  1  2  3  5  7 | 8  9  10  11  12 
           
           - cut1 = (cutR - cutL) / 2 + cutL
           - cut2 = len(nums3) / 2 - cut1
     
    - 找尋條件：
     L1 <= R2
     L2 <= R1
        --達成此條件，可以找到相對應的值

    index: 0  1      2   3  4  5
              L1     R1
    num1:  3  5  |   8   9
    num2:  1  2      7 | 10 11 12
                     L2  R2
                         
    num3:  1  2  3  5  7 | 8  9  10  11  12
        
        - 如果不符：
            - L1 > R2
                - 要左移
                (cutL, cut1 - 1)
            - L2 > R1
                - 要右移
                (cut1 + 1, cutR)
                
                --> 可以發現操作都在 nums1 上面
                --> 因為要在 nums1 上面進行 Binary Search，所以要有一個範圍，
                    因此，會先預設在 nums1 的左邊和右邊，設置 cutL 和 cutR。
                    
                    --> 問題點：平常在做 Binary Search 時，while 回圈是這樣設定  
                            while(L < R)
                    --> 但因為每一次 L 和 R 在 nums1 中會改變
                    --> 再者，我們是在 nums1 上面找尋 L 和 R 的位置，因此本回圈
                            while(cut1 <= nums1.length )        
                
                --> (有別於一般的 Binary Search，但不管如何，要想實作 Binary Search，都要了解“範圍”)
     
         Example:
    Example:
    index: 0  1  2  3  4  5
    num1:  3  5  8  9
    num2:  1  2  7  10 11 12
    
    Step_01:

    index: 0    1      2  3  4  5
           L1  R1
    num1:  3 |  5      8  9
    num2:  1    2      7  10 | 11 12
                          L2   R2
                     
    num3:  1  2  3  5  7 | 8  9  10  11  12    
    
    

    index: 0  1      2   3  4  5
              L1     R1
    num1:  3  5  |   8   9
    num2:  1  2      7 | 10 11 12
                     L2  R2
                 
                 
    num3:  1  2  3  5  7 | 8  9  10  11  12
    
    
     
    
'''
from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> int:
        # Edge Cases
        if len(nums1) == 0:
            return (nums2[(len(nums2) - 1) // 2 ] + nums2[len(nums2) // 2]) / 2.0
        
        # Make sure Num1 is the smaller one
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        # Calculate the total length of the combination array
        totalLength = len(nums1) + len(nums2)
        # 切點: 都從 0 開始 (但有些參考答案會從兩個陣列的中間開始，不影響結果)
        cut1 = 0
        cut2 = 0
        
        # cutL 和 cutR (輔助二分法範圍: 在 nums1 中進行Binary Search)
        cutL = 0
        cutR = len(nums1)
        
        # Assist for Min and Max value
        MIN_VAL = float('-inf')
        MAX_VAL = float('inf')
        
        # Using the while-loop to process the result
        while cutL <= cutR:
            cut1 = (cutR - cutL) // 2 + cutL
            # 因為最終左右兩邊個數一樣，確定了 cut1，就可以求得 cut2
            cut2 = totalLength // 2 - cut1
            
            # 藉由“切點”，找到左右兩邊的值
            L1 = MIN_VAL if cut1 == 0 else nums1[cut1 - 1]
            L2 = MIN_VAL if cut2 == 0 else nums2[cut2 - 1]
            R1 = MAX_VAL if cut1 == len(nums1) else nums1[cut1]
            R2 = MAX_VAL if cut2 == len(nums2) else nums2[cut2]
            
            # 比較切點值(3種情況)
            if L1 > R2:
                cutR = cut1 - 1
            elif L2 > R1:
                cutL = cut1 + 1
            else:
                # 代表找到了
                    # 偶數情況
                if totalLength % 2 == 0:
                    L1 = max(L1, L2)
                    R1 = min(R1, R2)
                    return (L1 + R1) / 2.0
                else:
                    return min(R1, R2)
            
            
            
            
            
            
            
            
            
        
        
        
        
        
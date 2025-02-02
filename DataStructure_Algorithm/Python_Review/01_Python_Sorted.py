'''
Timsort 是一種混合排序算法，由 Tim Peters 在 2002 年為 Python 設計。它結合了插入排序和歸併排序的優點，能夠在實際應用中提供非常好的性能。Timsort 的時間複雜度在最壞、平均和最佳情況下都是 O(n log n)，其中 n 是待排序元素的數量。

Timsort 的主要特點包括：

1.分段排序：Timsort 將數組分成若干個小段（稱為 run），每個 run 都是已經排序好的。
2.插入排序：對於每個小段，Timsort 使用插入排序來排序，因為插入排序在小數據集上非常高效。
3.歸併排序：將已排序的小段合併成更大的段，直到整個數組排序完成。
    Python 的內建 sort 方法和 sorted 函數都使用 Timsort 算法。

以下是 Timsort 的基本步驟：

將數組分成若干個小段，每個小段的長度至少為 32。
1. 使用插入排序對每個小段進行排序。
2. 使用歸併排序將已排序的小段合併成更大的段，直到整個數組排序完成。
3. 這使得 Timsort 在處理實際數據時非常高效，特別是當數據已經部分排序時。

在你的程式碼中，num.sort() 使用的就是 Timsort 算法。

'''

class Solution:
    
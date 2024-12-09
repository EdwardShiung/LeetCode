#include <iostream>
using namespace std;

/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105


    [Thought]
    1. newInterval 與 intervals 其中一個比較時
        - newInterval 在 intervals[i] 的左邊
        - newInterval 在 intervals[i] 的右邊
        - newInterval 涵蓋了 intervals
            - 更新 newInterval
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Set a results
        vector<vector<int>> results;
        // Using for-loop to get the results
        for(int i = 0; i < intervals.size(); i++) {
            // newInterval 小於 interval[i]
            if(newInterval[1] < intervals[i][0]) {
                results.push_back(newInterval);
                // Append the remaining intervals and return the result
                results.insert(results.end(), intervals.begin() + i, intervals.end());
                return results;
            }else if (newInterval[0] > intervals[i][1]) {
                results.push_back(intervals[i]);
            }else{
                // Merge intervals
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        results.push_back(newInterval);
        return results;
    }
};
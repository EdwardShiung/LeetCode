#include <iostream>
using namespace std;

/*

Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. 
For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104

*/


class Solution {
private:
    static bool compared(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        // Step 01 Sort the intervals
        sort(intervals.begin(), intervals.end(), compared);
        // Calculate how many intervals need to be removed.
        int count = 0;
        // First interval of ending point
        int endPosition = intervals[0][1];
        // Using for-lo op to verify over-lapping intervals
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < endPosition) {
                // if next interval is smaller than previous interval, should be counted
                count++;
                // Choose the smaller one to be endPosition
                endPosition = min(endPosition, intervals[i][1]);
            }else{
                endPosition = intervals[i][1];
            }
        }
        return count;
    }
};
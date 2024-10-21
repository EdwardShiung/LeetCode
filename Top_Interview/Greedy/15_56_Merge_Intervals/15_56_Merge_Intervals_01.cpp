#include <iostream>
using namespace std;

/*
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/


class Solution {
private:
    static bool compared(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Set a results array
        vector<vector<int>> results;
        // if no interval, return empty results
        if(intervals.size() == 0) return results;

        //sort the interval by left side
        sort(intervals.begin(), intervals.end(), compared);

        // if at least one interval, put the first interval to the results;
        results.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= results.back()[1]) {
                results.back()[1] = max(results.back()[1], intervals[i][1]);
            }else{
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
};
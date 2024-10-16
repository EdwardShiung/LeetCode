#include <iostream>
using namespace std;

class Solution {
private:
    static bool compared(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        // Step 01 Sort the intervals
        sort(intervals.begin(), intervals.end(), compared);
        int count = 
    }
}
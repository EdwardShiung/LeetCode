#include <iostream>
using namespace std;

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

    1 + 2 + 1 + 1 + 3 + 2 + 1 + 2 + 1


*/

class Solution {
public:
    int trap(vector<int>& height) {
        int index = height.size() - 1;
        int area = 0;
        int maxLeft = height[0];
        int maxRight = height[index];
        int left = 0;
        int right = index;
        while(left != right) {
            if(maxLeft <= maxRight) {
                left++;
                if(maxLeft > height[left]) {
                    area += abs(maxLeft - height[left]);
                }
                maxLeft = max(maxLeft, height[left]);
            }else {
                right--;
                if(maxRight > height[right]) {
                    area += abs(maxRight - height[right]);
                }
                maxRight = max(maxRight, height[right]);
            }
        }
        return area;
    }
};
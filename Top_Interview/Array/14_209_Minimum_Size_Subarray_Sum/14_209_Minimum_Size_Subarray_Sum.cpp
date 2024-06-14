#include<iostream>
#include<vector>
using namespace std;


/*
    [Method_01]: [Sliding Window Concept]

    [Thought]:
    1. If I don't use force method, the other way is to use sliding window method.
    2. Using sliding window need to know which pointer is beginner.
    3. Below we choose slow pointer to be a beginner, so once the sum is bigger than target, 
       we need to enter a small loop.

    The approach to this problem.

    Example:
    target = 7
    nums = [2,3,1,2,4,3]
    result = INT32_MAX
    subLength = 0


        1st:
                        [2,3,1,2,4,3]
        fast pointer     ^    
        slow pointer     ^
        slow(0)
        result = INT32_MAX
        subLength = 0
        
        Explain:        2 < 7
        --> Keep going to move on!

        2nd:
                        [2,3,1,2,4,3]
        fast pointer       ^    
        slow pointer     ^
        slow(0)
        result = INT32_MAX
        subLength = 0

        Explain:        2 + 3 < 7
        --> Keep going to move on!

        3rd:
                        [2,3,1,2,4,3]
        fast pointer         ^    
        slow pointer     ^
        slow(0)
        result = INT32_MAX
        subLength = 0

        Explain:        2 + 3 + 1 < 7
        --> Keep going to move on!


        4th:
                        [2,3,1,2,4,3]
        fast pointer           ^    
        slow pointer     ^
        slow(0)
        result = INT32_MAX
        subLength = 0

        Explain:        2 + 3 + 1 + 2 >= 7
        -->Because the sum >= 7, it needs to adjust the slow pointer.
            --> Compared results with sub-Length. Choose short one.
            1st:
            
            subLength = 3 - 0 + 1 = 4
            result = result < subLease ? result : subLength
                slow ++;
                            [2,3,1,2,4,3]
            fast pointer           ^    
            slow pointer       ^
            slow(1)
            result = 4
            subLength = 4
            Explain:     3 + 1 + 2 < 7

        5th:
                        [2,3,1,2,4,3]
        fast pointer             ^    
        slow pointer       ^
        slow(1)
        result = 4
        subLength = 4

        Explain:        3 + 1 + 2 + 4 >= 7
        -->Because the sum >= 7, it needs to adjust the slow pointer.
            
            1st:
            subLength = 4 - 1 + 1 = 4
            result = result < subLease ? result : subLength
                slow ++;
                            [2,3,1,2,4,3]
            fast pointer             ^    
            slow pointer         ^
            slow(2)
            result = 4
            subLength = 4
            Explain:     1 + 2 + 4 >= 7
            -->Because the sum >= 7, it needs to adjust the slow pointer.

            2nd:
            subLength = 4 - 2 + 1 = 3
            result = result < subLease ? result : subLength
                slow ++;
                            [2,3,1,2,4,3]
            fast pointer             ^    
            slow pointer           ^
            slow(3)
            result = 3
            subLength = 3
            Explain:     2 + 4 < 7

        6th:
                        [2,3,1,2,4,3]
        fast pointer               ^    
        slow pointer           ^
        slow(3)
        result = 3
        subLength = 3
        Explain:        2 + 4 + 3 >= 7

            1st:
            subLength = 5 - 3 + 1 = 3
            result = result < subLease ? result : subLength
                slow ++;
                            [2,3,1,2,4,3]
            fast pointer               ^    
            slow pointer             ^
            slow(4)
            result = 3
            subLength = 3
            Explain:     4 + 3 >= 7
            -->Because the sum >= 7, it needs to adjust the slow pointer.

            2nd:
            subLength = 5 - 4 + 1 = 2
            result = result < subLease ? result : subLength
                slow ++;
                            [2,3,1,2,4,3]
            fast pointer               ^    
            slow pointer               ^
            slow(5)
            result = 2
            subLength = 2
            Explain:     3 < 7
*/

class Solution{
public:
        int minSubArrayLen(int target, vector<int>& nums){
        
        //Initialize a Maximum numbers
        int result = INT32_MAX;
        int slow = 0;
        int subLength = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];

            while(sum >= target){
                //calculate sub-length
                subLength = i - slow + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[slow];
                slow ++;
            }
        }
        
        return result == INT32_MAX ? 0 : result;
    }
};

int main(){


    Solution solution;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};


    int minLength = solution.minSubArrayLen(target, nums);

    cout << minLength << endl;
    
    return 0;

}

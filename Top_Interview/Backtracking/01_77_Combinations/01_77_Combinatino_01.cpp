#include <iostream>
#include <vector>
using namespace std;

/*

    [Question]
    Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

    You may return the answer in any order.

    

    Example 1:

    Input: n = 4, k = 2
    Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
    Explanation: There are 4 choose 2 = 6 total combinations.
    Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

    Example 2:

    Input: n = 1, k = 1
    Output: [[1]]
    Explanation: There is 1 choose 1 = 1 total combination.
    

    Constraints:

    1 <= n <= 20
    1 <= k <= n

    [Thought]

    Step-by-Step Visualization

    Initial Call:

    combine(4, 2) calls backtracking(4, 2, 1).

    First Level of Recursion:

        Loop i from 1 to 4:
        i = 1: path = [1]
        Call backtracking(4, 2, 2)
        Second Level of Recursion:

        Loop i from 2 to 4:
        i = 2: path = [1, 2]
        path.size() == 2, add [1, 2] to results
        Backtrack: path = [1]
        i = 3: path = [1, 3]
        path.size() == 2, add [1, 3] to results
        Backtrack: path = [1]
        i = 4: path = [1, 4]
        path.size() == 2, add [1, 4] to results
        Backtrack: path = [1]
        Back to First Level:

    Continue Loop i from 1 to 4:
    i = 2: path = [2]
    Call backtracking(4, 2, 3)

    Second Level of Recursion:

        Loop i from 3 to 4:
        i = 3: path = [2, 3]
        path.size() == 2, add [2, 3] to results
        Backtrack: path = [2]
        i = 4: path = [2, 4]
        path.size() == 2, add [2, 4] to results
        Backtrack: path = [2]
        Back to First Level:

        Continue Loop i from 1 to 4:
        i = 3: path = [3]
        Call backtracking(4, 2, 4)
        
    Second Level of Recursion:

        Loop i from 4 to 4:
        i = 4: path = [3, 4]
        path.size() == 2, add [3, 4] to results
        Backtrack: path = [3]
        Back to First Level:

        Continue Loop i from 1 to 4:
        i = 4: path = [4]
        Call backtracking(4, 2, 5)
        Since startIndex = 5 is greater than n, this call immediately returns without any further action.

*/

class Solution {
public:
    vector<int> path;
    vector<vector<int>> results;

    void backtracking(int n, int k, int startIndex) {
        // 終止條件：
        if(path.size() == k) {
            results.push_back(path);
            return;
        }
        // 單層循環
        for(int i = startIndex; i <= n; i++) {
            // 處理節點
            path.push_back(i);
            // 遞歸：控制樹的縱向遍歷
            backtracking(n, k, i + 1);
            // 回朔：撤銷處理的節點
            path.pop_back();
        }
    }   

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return results;
    }
};
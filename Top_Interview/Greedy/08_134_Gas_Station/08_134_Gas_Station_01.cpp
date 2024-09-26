#include <iostream>
using namespace std;

/*

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
 

Constraints:

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104


[Thought]
    1. There are two solutions. 
        - The first one is kind of brutal force solution.
            - Reference 01
                - The time complexity is too high O(n^2)
        - The second one is optimized solution.
            - Reference 02
        - Using "Greedy"
            - Reference 03
[Skill]
    1. modulus operations with array index
    2. understanding the different between for loop and while loop
        // for loop: from the begin to the end --> it's kind of line loop
        // while loop: circular loop 


*/

class Solution {
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // record the total oil usage
        int total = 0;
        // record the minium value
        int min = INT_MAX;
        // Determine the total oil usage
            // During calculation, we can
        for(int i = 0; i < gas.size(); i++) {
            // Calculate the usage
            total += gas[i] - cost[i];
            // Record the minimum
            if(total < min) min = total;
        }

        // Case 1: if total smaller than zero, it means that it could not get any result. 
            // Return -1
            if(total < 0) return -1;

        // Case 2: if total greater than or equal to zero, it means that the result at index 0;
            if(min >= 0) return 0;

        //Case 3: if total == 0  but min !=0, we need to find out which index could be the starting point.
            // Using for loop from the ending point to the beginning point.
            // If the accumulated value could equal to the min, it means that the starting point is in that index.
            for(int i = gas.size() - 1; i >=0; i-- ) {
                min += gas[i] - cost[i];
                if(min >= 0){
                    return i;
                }
            }
        // Just in case the program get error, so we give the program return a -1
        return -1;            
    }
};


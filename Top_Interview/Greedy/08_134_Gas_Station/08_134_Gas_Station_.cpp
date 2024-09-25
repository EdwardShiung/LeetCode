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
[Skill]
    1. modulus operations with array index
    2. understanding the different between for loop and while loop
        // for loop: from the begin to the end --> it's kind of line loop
        // while loop: circular loop 


*/

class Solution {
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++) {
            // Record the rest of oil
            int rest = gas[i] - cost[i];
            // From i index, we need to know whether the gas is enough to the rest of road.
            int index = (i + 1) % gas.size();
            // Start to run the rest of distance
                // First Limitation: Rest should greater zero.
                    // if rest smaller than zero, we don't have enough gas to run the rest of road.
                // Second Limitation: index != i.
                    // if index == i, the loop should stop.
            while(rest > 0 && index != i) {
                rest += gas[index] - cost[index];
                index = (index + 1) % gas.size();
            }
            // Here is very important.
            // There are two requirements that could work and return i.
                // Rest should greater than zero.
                // index should equal i. The reason is that we need to make sure we can run the whole index, not only one at i index.
            if(rest >=0 && index == i) return i;
        }
        return -1;
    }
};


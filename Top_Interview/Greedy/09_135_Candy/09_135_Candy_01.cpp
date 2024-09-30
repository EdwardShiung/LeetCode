#include <iostream>
using namespace std;

/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104



[Thought]
    
    1. Step 01: Give one for each student.
    2. Step 02: From the begin to the end (Left -> Right Loop), if left is bigger, add one more.
    3. Step 03: From the begin to the end (right -> left Loop), if right is bigger, add one more. 
    4. Calculate the total of candies

*/


class Solution {
public:
    int candy(vector<int>& ratings) {

        // Step 01: Give one for each student.
        vector<int> candyAssign(ratings.size(), 1);

        // Step 02: From the begin to the end (Left -> Right Loop), if right is bigger, add one more.
        for(int i  = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]) candyAssign[i] += 1;
        }

        // Step 03: From the end to the begin (right -> left Loop), if left is bigger, add one more.
        for(int i  = ratings.size() - 1; i > 0; i--) {
            if(ratings[i - 1] < ratings[i]) candyAssign[i] += 1;
        }

        // Step 04: total
        int total = 0;
        for(int i = 0; i < candyAssign.size(); i++) {
            total += candyAssign[i];
        }

        return total;
    }
};


#include <iostream>
#include <list>
using namespace std;

/*
You are given an array of people, people, 
which are the attributes of some people in a queue (not necessarily in order). 
Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. 
The returned queue should be formatted as an array queue, 
where queue[j] = [hj, kj] is the attributes of the jth person in the queue 
(queue[0] is the person at the front of the queue).

 

Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.

[Thought]:

    1. Doing Greedy, one thing is very important. If there are at least two parameter, such as height(h) and people(k), 
    the best solution is to fix one parameter and move another.

    2. We can try to move people(k) first, and you find out that could be far away from the answer.

    3. However, if we move the height(h) parameter, you will find out when you fix the height parameter,
    it will be easy to adjust the k parameter, which could insert to the index by k.

    4. Vector is not a good container. So, it could be optimize by other container, such as linked list.

[Reflection]:
    1. The problem for the solvation is that vector is not good for time complexity, so as you can see, the results is not optimized.
        - In order to optimize the time complexity, we can use linked list to solve for that.
        - Please see the file_02.
    
*/

class Solution {
public:
    // Height (from Tall to Short) -- If tall is the same, I  will compare the "k".
    // When I compared the "k", pick the small one in the front and large one in the latter.
    static bool compared(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Step 1: Sort the height from tall to short (if the tall is the same, I will compare the "k".)
        sort(people.begin(), people.end(), compared);
        // Using List not vector to optimize insertion time complexity 
        // The underlying implementation of a list is a linked list, which makes insertion much more efficient than a vector.
        list<vector<int>> queue;
        // Using for-loop to rank the array
        for(int i = 0; i < people.size(); i++) {
            // Get the K information.(We need to use that to insert the data by index.)
            int position = people[i][1];
            // Using the it to get the index
            std::list<vector<int>>:: iterator it = queue.begin();
            while(position--) {
                it++;
            }
            queue.insert(it, people[i]);
        }
        return vector<vector<int>>(queue.begin(), queue.end());
    }
};



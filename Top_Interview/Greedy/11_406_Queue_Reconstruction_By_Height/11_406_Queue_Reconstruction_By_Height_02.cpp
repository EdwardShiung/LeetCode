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
            // Initialize an iterator
            std::list<vector<int>>:: iterator it = queue.begin();
            /*
            std::list<vector<int>>::這種C++中模板類型的常規表示法。
            這裡的意思是我們在使用一個特定的類型std::list，而這個list存儲的是vector<int>型別的元素。
            來拆解一下這個表示法：

            std::list<vector<int>>

            std::list：C++標準庫中的雙向鏈表類型，是一個模板類（template class），可以存儲任意類型的元素。
            vector<int>：這表示每個list中的元素是vector<int>，即一個存放整數的動態數組。
            也就是說，list的每一個節點裡存放的是一個整數向量。
            ::（範圍解析運算符）：
            這個符號用來訪問類或命名空間中的成員。
            在這裡，我們想定義或使用某個與list<vector<int>>相關的東西，比如迭代器，所以需要使用範圍解析運算符。

            例子：
            假設你需要聲明一個迭代器來遍歷std::list<vector<int>>中的元素，那麼就會這樣寫：

            cpp
            std::list<vector<int>>::iterator it;
            這表示你聲明了一個迭代器it，它可以用來指向或操作std::list<vector<int>>中的元素。

            這種寫法的結構：
            模板類型（template class）：std::list和std::vector都是模板類型，這些模板類型可以接受其他類型作為參數。
            例如，std::list<vector<int>>表示這個list的每個元素是一個vector<int>。
            範圍解析符號（::）：用來訪問模板類型的成員，像迭代器（iterator）或其他成員函數。
            所以這並不是「專門的」寫法，而是C++模板和範圍解析運算符的常見用法。
            */
            while(position--) {
                it++;
            }
            queue.insert(it, people[i]);
        }
        return vector<vector<int>>(queue.begin(), queue.end());
    }
};



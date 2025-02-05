#include <iostream>
using namespace std;
/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).


Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?

*/

// Define the ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(NULL) {};
};


class Solution {
public:

    bool hasCycle(ListNode* head) {
        // Edge Case
        if(head == NULL || head->next == NULL) return false;

        // Create slow and fast pointer
        // Slow pointer
        ListNode* slow = head;
        // Fast pointer
        ListNode* fast = head;
        /*
            為什麼需要檢查 fast 和 fast->next？
            因為 fast 每次移動兩步，如果列表長度不足或沒有環，fast 很可能會指向空指標（NULL）。
            此時若存取 fast->next，會導致程式崩潰。
        */
        // Using while loop to detect the cycle
        while(fast != NULL && fast->next != NULL) {
            // fast pointer has two times in speed than slow pointer
            fast = fast->next->next;
            slow = slow->next;
            
            // fast == slow means it finds out the cycle
            if(fast == slow) return true;
        }

        return false;
    }
};

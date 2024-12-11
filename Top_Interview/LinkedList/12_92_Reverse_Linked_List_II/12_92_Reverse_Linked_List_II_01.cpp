#include <iostream>
using namespace std;

/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(NULL) {};
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case
        if(head->val != NULL && head->next == NULL) return head;
        // Set a dummyHead
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        // Using a pre and curr pointers to iterate the head linked list
        ListNode *pre = dummyHead;
            // Set the pre pointer: Adjusting the pre node on it's actual index
        for(int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
            // Set the curr pointer
        ListNode *curr = pre->next;


        // Reverse the specific index by pre, curr, and forw pointer
        for(int j = 0; j < right - left; j++) {
            // Set the forw pointer
            ListNode *forw = curr->next;
            // current node reverse with forward node
            curr->next = forw->next;
            // forward node point to current node
            forw->next = pre->next;
            // previous node point to forward node
            pre->next = forw;
        }

        return dummyHead->next;
    }
};
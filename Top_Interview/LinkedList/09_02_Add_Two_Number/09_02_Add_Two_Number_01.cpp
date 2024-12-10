#include <iostream>
using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


    [Thought]:

    1. Understand why we use the dummy Head.
    2. Understand pointer to manipulate the link list node.
*/


/*
 * Definition for singly-linked list.
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Set a fake head
        ListNode *dummyHead = new ListNode(0);
        // Set a pointer point to dummyHead
        ListNode *curr = dummyHead;
        // Set a Carry
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0) {
            // Get the number from l1
            int x = (l1 != NULL) ? l1->val : 0;
            // Get the number from l2
            int y = (l2 != NULL) ? l2->val : 0;

            // Sum x and y with carry 
            int sum = x + y + carry;
            carry = sum / 10;

            // Create a node(we have a fake node)
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Move to the next Node in l1
            if(l1 != NULL) l1 = l1->next;
            // Move to the next Node in l2
            if(l2 != NULL) l2 = l2->next;
        }

        return dummyHead->next;
    }
};
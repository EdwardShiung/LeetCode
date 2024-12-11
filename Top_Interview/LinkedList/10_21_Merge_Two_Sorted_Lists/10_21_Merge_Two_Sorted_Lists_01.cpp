#include <iostream>
using namespace std;

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:
Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(NULL) {};
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        // Edge Case
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        // 這個 Edge Case，不一定需要
        if(list1 == NULL && list2 == NULL) return list1;

        // Set a new ListNode by using dummyHead
        ListNode *dummyHead = new ListNode(0);
        // Using a pointer to point the new ListNode
        ListNode *curr = dummyHead;

        // Using while loop to merge two linked list
        // 只要有其中一遍歷為 NULL，則停止
        while(list1 != NULL && list2!= NULL) {
            // 比較 list1 和 list2 當前的值，並賦予給 new linked list
            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        // 如果其中一個 list 已經停止了，剩餘的就直接給予 new linked list 
        curr-> next = (list1 != NULL) ? list1 : list2;

        // return new linked list
        return dummyHead->next;

    }
};
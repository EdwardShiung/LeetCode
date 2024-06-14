#include<iostream>
using namespace std;




struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(NULL){};
};


// Declare
// printListNode Declare
void printListNode(ListNode* list);


class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {

            // Set a dummyHead
            ListNode* dummyHead = new ListNode(0);
            dummyHead->next = head;

            // Set a pre pointer
            ListNode* pre = dummyHead;
            // Set a cur pointer
            ListNode* cur = dummyHead;

            // Count number of nodes
            int count = 0;
            // Don't forget to remember to set the head to cur pointer. (We have to count the result)
            cur = head;
            while(cur != NULL) {
                cur = cur->next;
                count++;
            }

            // If n is greater than the length of the list, return head unchanged
            if(count < n) {
                return head;
            }
            
            // cur: Reset to the dummyHead to start finding the target node
            cur = dummyHead;
            for(int i = 0; i < count - n + 1; i++) {
                cur = cur->next;
            }

            // pre: Find the previous node to the target node
            for(int i = 0; i < count - n ; i++) {
                pre = pre->next;
            }

            // Remove Nth node. Connext the pre node to the rest of cur node.
            pre->next = cur->next;

            // Return result List
            ListNode* results = dummyHead->next;

            // Delete dummyHead;
            delete dummyHead;

            return results;
    }
};


void printListNode(ListNode* list) {
    ListNode* cur = list;
    while(cur != NULL) {
        int val = cur->val;
        cout << "The value: "<< val << " ";
        cur = cur->next;
    }
    cout << endl;
}



int main(){
    
    // Create a List [1,2,3,4];
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    printListNode(head);
    
    // Set Nth remove number
    int nTh = 2;

    // Using Solution Class and function
    Solution sol;
    sol.removeNthFromEnd(head, nTh);

    // Print it out
    printListNode(head);

}
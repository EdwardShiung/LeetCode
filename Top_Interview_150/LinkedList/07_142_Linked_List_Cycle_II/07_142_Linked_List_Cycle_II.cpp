#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(NULL) {};
};

void printLinkedList(ListNode* head);

void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while(curr != NULL) {
        int val = curr->val;
        cout << val << " ";
        curr = curr->next;
    }
    cout << endl;

}

class Solution {
    public:
        ListNode* delectCycle(ListNode* head) {
            
            // Step 1: Check if the list is empty or has only one node
            if(head == nullptr || head->next == nullptr) return nullptr;
            
            // Create two pointer: Fast & Slow
            ListNode* fast = head;
            ListNode* slow = head;

            // Step 2: Detect if there is a cycle in the list
            while(fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow) break;
            }

            // Step 3: After Step 2, if there is no cycle, return null
            if(fast == nullptr || fast->next == nullptr) return nullptr;

            // Step 4: after Step 2, if there is a cycle, find the starting point.
            // Reset the slow pointer to the starting point (fast pointer doesn't need to reset)
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            //Slow is now at the starting point of the cycle
            return slow;
        }
};

int main() {
    ListNode* list_A = new ListNode(3);
    list_A->next = new ListNode(2);
    list_A->next->next = new ListNode(0);
    list_A->next->next->next = new ListNode(-4);
    printLinkedList (list_A);
}
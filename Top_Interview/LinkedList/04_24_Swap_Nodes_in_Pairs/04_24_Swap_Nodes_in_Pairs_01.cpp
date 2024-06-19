#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){};
};

void printLinkedList(ListNode* list) {
    ListNode* curr = list;
    while(curr != NULL) {
        int val = curr->val;
        cout << val << " ";
        curr = curr->next;
    }
    cout << endl;
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        while(curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* tmp = curr->next;
            ListNode* tmp_2 = curr->next->next->next;

            curr->next = curr->next->next;
            curr->next->next = tmp;
            curr->next->next->next = tmp_2;

            // Move two node
            curr = curr->next->next;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    };
};


int main() {
    
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    printLinkedList(list);

    Solution sol;

    list = sol.swapPairs(list);
    printLinkedList(list);

    return 0;

}
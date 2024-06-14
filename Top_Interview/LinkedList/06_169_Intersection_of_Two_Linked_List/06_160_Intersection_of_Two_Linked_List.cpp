#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(NULL){};
};

void printLinkedList(ListNode* list);

void printLinkedList(ListNode* list) {
    ListNode* cur = list;
    while(cur != NULL) {
        int val = cur->val;
        cout << val << " ";
        cur = cur->next;
    }
    cout << endl;
}


class Solution {
    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

            // Set curr_A pointer
            ListNode* curr_A = headA;
            // Set curr_B pointer
            ListNode* curr_B = headB;

            // Set A length
            int length_A = 0;
            // Set B length
            int length_B = 0;

            // Calculate A length
            while(curr_A != NULL) {
                length_A++;
                curr_A = curr_A->next;
            }

            // Calculate B length
            while(curr_B != NULL) {
                length_B++;
                curr_B = curr_B->next;
            }

            // curr_A Back to the headA
            curr_A = headA;
            // curr_B Back to the headB
            curr_B = headB;

            // Using while-loop to make the same length
            while(length_A != length_B) {
                if(length_A > length_B) {
                    curr_A = curr_A->next;
                    length_A--;
                }else{
                    curr_B = curr_B->next;
                    length_B--;
                }
            }

            // Search the same pointer
            while(curr_A != NULL) {
                if(curr_A == curr_B) {
                    cout << curr_A <<endl;
                    return curr_A;
                };
                curr_A = curr_A->next;
                curr_B = curr_B->next;
            }

            // If not find the same point, return NULL
            cout << "NULL" << endl;
            return NULL;
        };
};



int main(){
    ListNode* list_A = new ListNode(4);
    list_A->next = new ListNode(1);
    list_A->next->next = new ListNode(8);
    list_A->next->next->next = new ListNode(4);
    list_A->next->next->next->next = new ListNode(5); 

    ListNode* list_B = new ListNode(5);
    list_B->next = new ListNode(6);
    list_B->next->next = new ListNode(1);
    list_B->next->next->next = new ListNode(8);
    list_B->next->next->next->next = new ListNode(4);
    list_B->next->next->next->next->next = new ListNode(5);

    printLinkedList(list_A);
    printLinkedList(list_B);

    Solution sol;
    sol.getIntersectionNode(list_A, list_B);

    return 0;
}



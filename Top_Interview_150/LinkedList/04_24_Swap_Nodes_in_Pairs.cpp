#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    /*
        1. ListNode(int val)：這是構造函數的宣告部分。它告訴編譯器這是一個接受一個整數參數 val 的構造函數。
        2. : val(val), next(NULL)：這是初始化列表（initializer list）。
            初始化列表是在構造函數體之前的一部分，用於初始化成員變數。
            它的格式是 : 成員變數(初始值), 成員變數(初始值)。這裡：

            (1) val(val)：將構造函數的參數 val 的值賦給成員變數 val。
            
            --> 注意這裡的 val 左邊是成員變數，右邊是構造函數的參數。
            
            (2) next(NULL)：將成員變數 next 初始化為 NULL。
    */
    ListNode(int val): val(val), next(NULL){};
};

class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            // Set a virtual head to the List
            ListNode* dummyHead = new ListNode(0);
            dummyHead->next = head;
            // Set a curr pointer
            ListNode* curr = dummyHead;
            while((curr->next != NULL) && (curr->next->next != NULL)) {

                // Record temp node
                ListNode* temp = curr->next;

                curr->next = curr->next->next;


                curr->next->next = temp;


                //Move two nodes for next round
                curr = curr->next->next;
            }
            return head;
        }
};



int main(){

}
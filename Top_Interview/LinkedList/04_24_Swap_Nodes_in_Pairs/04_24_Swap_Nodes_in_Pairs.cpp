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
        // 設置一個虛擬節點
        ListNode* dummyHead = new ListNode(0); 
        // 将虚拟头结点指向head，这样方便后面做删除操作
        dummyHead->next = head; 
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            // 记录临时节点
            ListNode* tmp = cur->next; 
            // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; 

            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
        };
};



int main(){
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
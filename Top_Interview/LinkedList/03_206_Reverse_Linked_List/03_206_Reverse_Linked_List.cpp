#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(NULL){};
};



class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            // curr
            ListNode* curr = head;
            // pre
            ListNode* pre = NULL;
            // temp
            ListNode* temp;
            while(curr != NULL) {

                // pre 在 curr 前面
                // 邏輯： pre  現在指 null，但開始後，指向頭節點，之後以此類推
                // 邏輯： curr 現在指 head，但開始後，指向第二個節點
                // Step 01: 先保留 curr 下一個位置 
                temp = curr->next;
                // Step 02:  翻轉
                curr->next = pre;
                // Step 03: 更新 pre (pre到下一個位置)
                pre = curr;
                // Step 04 : 更新 curr (curr 到下一個位置)
                curr = temp;
            }
            return pre;
        }   
};




int main(){

}
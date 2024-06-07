#include<iostream>
using namespace std;

struct ListNode{
    //節點上儲存的值
    int val;
    //指向下一個節點
    ListNode *next;
    //節點構造函數
    ListNode(int x) : val(x), next(NULL){};
};


class Solution{
    public:
    ListNode* removeElements(ListNode*head, int val){
        
        // 設置一個虛擬 head
        ListNode* fakeHead = new ListNode(0);
        // 虛擬 head 連到 head
        fakeHead->next = head;
        ListNode* cur = fakeHead;
    
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{  
                cur = cur->next;
            }
        }
        head = fakeHead->next;
        delete fakeHead;
        return head;
    }
};


int main(){
    int head[] = {1,2,6,3,4,5,6};
    int val = 6;
}
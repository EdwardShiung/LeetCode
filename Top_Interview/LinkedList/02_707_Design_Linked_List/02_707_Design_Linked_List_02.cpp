#include <iostream>
using namespace std;


class MyLinkedList {
public:
    // Define a struct
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val): val(val), next(nullptr){};
    };

    // Initialize the Linked List with dummyHead
    MyLinkedList(){
        _dummyHead = new ListNode(0);
        _size = 0;
    };

    // Add a node at head
    void addAtHead(int val) {
        // Create a new Node
        ListNode* newNode = new ListNode(val);
        // 順序不能錯
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // Add a node at tail
    void addAtTail(int val) {
        // Create a new Node
        ListNode* newNode = new ListNode(val);
        // Create a pointer
        ListNode* curr = _dummyHead;
        // Search the final index
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
        _size++;
    }

    // Add a node at index
    void addAtIndex(int index, int val) {
        // Index > Size or index < 0, return 
        if(index > _size || index < 0) return;

        // Create a new Node
        ListNode* newNode = new ListNode(val);
        // Create a pointer
        ListNode* curr = _dummyHead;
        // Search Index and Insert the val
        while(index--) {
            curr = curr->next;
        }

        // 順序不能錯
        newNode->next = curr->next;
        curr->next = newNode;
        _size++;
    }

    // Get a node value by index
    int get(int index) {
        if(index > (_size - 1) || index < 0) {
            return -1;
        }
        ListNode* curr = _dummyHead->next;
        while(index--) {
            curr = curr->next;
        }
        int result = curr->val;
        cout << result << endl;
        return result;
    }

    // Print the Linked List
    void printLinkedList() {
        ListNode* curr = _dummyHead;
        while(curr->next != nullptr) {
            cout << curr->next->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Delete one of the node by index
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0) {
            return;
        }
        // Create a pointer
        ListNode* curr = _dummyHead;
        while(index--) {
            curr = curr->next;
        }
        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }

private:
    ListNode* _dummyHead;
    int _size;
};



int main() {
    MyLinkedList LinkedList;

   LinkedList.addAtHead(1);
   LinkedList.addAtHead(2);
   LinkedList.addAtHead(3);
   LinkedList.printLinkedList();

   LinkedList.addAtTail(77);
   LinkedList.printLinkedList();

   LinkedList.naddAtIdex(3,66);
   LinkedList.printLinkedList();
   LinkedList.get(0);
   LinkedList.deleteAtIndex(1);
   LinkedList.printLinkedList();
}
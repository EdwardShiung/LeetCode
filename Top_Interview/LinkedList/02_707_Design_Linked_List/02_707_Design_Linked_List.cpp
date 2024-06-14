#include<iostream>
using namespace std;

class MyLinkedList{

public:

// Define a Linked List Struct
struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int val): val(val), next(NULL){};
};

    MyLinkedList() {
        //Initialized the LinkedList (Not a real head)
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    //Retrieve the index of Linked List, if index is not a validate num, return -1
    //Index start from 0.
    int get(int index) {

        if(index > (_size - 1) || index < 0) {
            return - 1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index --) {
            cur = cur->next;
        }
        return cur->val;
    }

    //Add a node of value before the first element of the linked list.
    //After the insertion, the node will be the first node of the linked list.
    void addAtHead(int val) {

        // Create a new Node
        LinkedNode* newNode = new LinkedNode(val);

        // Add the new Node to be the head but before the dummyHead
        newNode->next = _dummyHead->next;
        
        // dummyHead still need to be the first one
        _dummyHead->next = newNode;
        _size++;
    }
    //Append a node of value as the last element of the linked list
    void addAtTail(int val) {

        // Create a new Node
        LinkedNode* newNode = new LinkedNode(val);

        //Find the last element of the linked list
        LinkedNode* cur = _dummyHead;
        while(cur->next != NULL) {
            cur = cur->next;
        }

        //Append the newNode in the last
        cur->next = newNode;
        _size++;
    }

    //Add a node of value before the index node in the linked list.
    //If the index equals the length of the linked list, the node will be appended to the end of the linked list.
    //If index is greater than the length, the node will not be inserted.
    void addAtIndex(int index, int val) {
        // If index is greater than the length, the node will not be inserted.
        if(index > _size) return;
        // Index could not smaller than 0
        if(index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // deleteAtIndex
    void deleteAtIndex(int index) {
        // Basic Limitation
        if(index >= _size || index < 0) {
            return;
        }

        LinkedNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }

        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;

        tmp = NULL;
        _size--;
    }
private:
    int _size;
    LinkedNode* _dummyHead;

};
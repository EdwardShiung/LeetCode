#include <iostream>
#include <stdlib.h>     


struct ListNode {
    ListNode *prev;
    int val;
    ListNode *next;
}*start;

typedef ListNode* NODE;

/*
    為什麼建立 struct Node 後，通常還會再建立 typedef ?

    1. 簡化程式碼
    --> 直接使用 struct node 每次都需要寫完整的 struct node，這在代碼中顯得繁瑣。
        使用 typedef 可以簡化代碼，使其更簡潔易讀。例如：

        struct Node {
            struct node* prev;
            struct node* next;
            int val;
        };

        typedef struct node* NODE;

        // 使用 typedef 之後，可以這樣寫
        NODE newNode = (NODE)malloc(sizeof(struct node));

        // 不使用 typedef，需要這樣寫
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    2. 可讀性和可維護性
    --> typedef 可以增加代碼的可讀性和可維護性。特別是當使用指針類型時，typedef 可以更清楚地表達意圖。例如：
        typedef struct node* NODE;

    3. 抽象數據類型 (Abstract Data Type)
    --> 使用 typedef 可以更方便地實現抽象數據類型。這樣在修改底層數據結構時，只需要改變 typedef 定義，而不需要修改所有使用該類型的地方。
        例如，如果將來需要把 struct node 改為其他結構，只需修改 typedef 定義，而不需修改其他代碼。


*/


//Function to Create a Double Linked List
void create_list(int num) {
    NODE newData = (NODE)malloc(sizeof(ListNode));
    newData->val = num;
    newData->next = nullptr;

    if (start == nullptr) {
        newData->prev = nullptr;
        start = newData;
    } else {
        NODE curr = start;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newData;
        newData->prev = curr;
    }
}


void display() {
    if (start == nullptr) {
        std::cout << "\nList is empty\n";
        return;
    }
    NODE curr = start;
    std::cout << "\nList is:\n";
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}



int main() {
int choice, n, m, po, i;
    NODE start = nullptr;
    while (true) {
        std::cout << "\n1. Create List\n";
        std::cout << "8. Exit\n";
        std::cout << "5. Display\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nHow many nodes you want: ";
                std::cin >> n;
                for (i = 0; i < n; i++) {
                    std::cout << "\nEnter the element: ";
                    std::cin >> m;
                    create_list(m);
                }
                break;
            case 5:
                display();
                break;
            case 8:
                exit(0);
            default:
                std::cout << "\nWrong choice\n";
        }
    }
    return 0;
}
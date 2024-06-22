#include<iostream>
//STL 模板 搭建 Linked List
#include<list>

using namespace std;

void printLinkedList(const list<int>& L) {
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void LinkedList() {
    
    // 默認構造函數：list<T> lst              -->  list 採用模板類型實踐，物件為默認的構造函示
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);

    cout << "第一個 Linked List" << endl;
    printLinkedList(L1);

    // 區間構造函數：list(begin, end)         -->  構造函數將[beg,end)區間中的元素，拷貝給本身
    list<int>L2(L1.begin(), L1.end());
    cout << "第二個 Linked List" << endl;
    printLinkedList(L2);

    // 拷貝構造函數：list(const list &lst)    --> 構造函數將 n 個  elem 拷貝給本身
    list<int>L3(L2);
    cout << "第三個 Linked List" << endl;
    printLinkedList(L3);

    // 初始化為多個相同元素：list(n, elem)     -->  拷貝構造函數
    list<int>L4(10, 1000);
    cout << "第四個 Linked List" << endl;
    printLinkedList(L4);

}

int main() {
    
    LinkedList();
    
    return 0;
}

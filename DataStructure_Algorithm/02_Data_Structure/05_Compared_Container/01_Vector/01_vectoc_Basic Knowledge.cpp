/*
1. std::vector 為動態陣列：
    - 末位插入和末位刪除效率高
        - 中間插入和中間刪除”最慢“
    - "動態" 擴展容量(dynamic array)，隨機訪問
*/
/*
    操作整理：
        添加元素	     push_back(val)	在末尾添加一个元素
        删除元素	     pop_back()	删除末尾元素
        获取大小	     size()	返回当前元素个数
        随机访问	     v[index] 或 v.at(index)	获取指定位置的元素
        插入元素	     insert(pos, val)	在指定位置插入一个元素
        删除指定位置元素  erase(pos)	删除指定位置的元素
        清空容器	     clear()	删除所有元素
        检查是否为空	  empty()	返回是否为空
        访问首尾元素	  front() / back()	获取第一个或最后一个元素
        动态容量	     capacity()	返回当前容量
        预分配容量	     reserve(n)	预分配至少能容纳 n 个元素的空间
        排序（需要算法库）	sort(v.begin(), v.end())	将元素按升序排序
*/
#include <iostream>
// 引入 vector 函式庫
#include <vector>
using namespace std;

int main() {
    // Initialization
    // 有四種初始化方法：

    // 1. Empty Vector
    vector<int> v1;

    // 2. Vector of Size with default values(0 for int)
    vector<int> v2(3);

    // 3. Vector of Size 3 with all values initialized to 10
    vector<int> v3(3, 10);

    // 4. Vector initialized with a list of values
    vector<int> v = {1, 2, 3};


    // Common Operations
    // 1. Adding Element 添加新的 "元素 4" 到 vector 最後一位
    v.push_back(4);      

    // 2. Removing Element 刪除最後一個元素
    v.pop_back();         

    // 3. Inserting Element 在開頭，插入 0
    v.insert(v.begin(), 0);

    // 4. Erasing Element 刪除開頭元素 
    v.erase(v.begin()); 

    // 5. Accessing Elements
        // operator []: Accesses an element at a specified position
        // Accesses the second element
    int num = v[1];
        // at(): Accesses an element with bounds checking
        // Accesses the first element with bounds checking
    int x = v.at(1);

    // 6. Size and Capacity
        // size(): Returns the number of elements in the vector.
    int size = v.size();
        // capacity(): Returns the size of the storage space currently allocated for the vector.
        int capacity = v.capacity();
        // resize(): Resizes the vector to contain a specified number of elements.
        v.resize(10);

    // 7. Iterators
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    // 遍歷結果  
    for (int x : v) {
        cout << x << " "; 
    }
    return 0;
}

/*
    備註：
    1.v[index] 和 v.at(index) 的区别：

        - v[index] 不会进行边界检查，访问越界可能导致未定义行为。
        - v.at(index) 会检查边界，越界时抛出 std::out_of_range 异常。
        动态扩展的性能：

    2. vector 会自动扩展容量，但扩展时可能需要重新分配内存，导致性能下降。
        如果提前知道所需容量，可以使用 reserve(n) 来减少扩展次数。
        与 C 数组的区别：

    3. vector 的大小动态调整，更加灵活。提供了丰富的操作方法，而 C 数组是静态的、大小固定。
*/
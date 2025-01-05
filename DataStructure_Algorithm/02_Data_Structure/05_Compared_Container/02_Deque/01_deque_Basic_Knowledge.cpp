/*

    1. std::deque（雙端隊列，Double-Ended Queue）
        - 是一個動態序列容器
        - 支持在 兩端 高效插入和删除元素
        - 與 vector 相似，但 deque 支持在兩端插入和删除，而 vector 只能高效操作末尾

    2. deque 的特点
        - 双端操作：
            可以在容器的头部和尾部快速插入和删除元素。
        - 动态扩展：
            deque 的大小可以动态增长或缩小。
        - 随机访问：
            支持通过索引随机访问（性能与 vector 相当）。
        效率：
            头部和尾部插入/删除的效率比 vector 高（vector 需要移动数据）。
            实现机制：
            基于分段数组结构，与 vector 的单块连续内存不同。
    
    3.方法/操作	描述
        push_back(val)	在尾部添加元素。
        push_front(val)	在头部添加元素。
        pop_back()	删除尾部元素。
        pop_front()	删除头部元素。
        front()	返回第一个元素（不删除）。
        back()	返回最后一个元素（不删除）。
        size()	返回元素数量。
        empty()	检查是否为空，返回 true 或 false。
        clear()	清空所有元素。
        at(index)	返回指定索引的元素，带边界检查（越界会抛出异常）。
        [index]	返回指定索引的元素，不带边界检查（越界未定义行为）。
        insert(pos, val)	在指定位置插入元素。
        erase(pos)	删除指定位置的元素。
        resize(n)	调整大小为 n，如果扩展则填充默认值。
        swap(dq)	交换两个 deque 的内容。

    4. 與 vector 的區別
        特性	        std::vector	                std::deque
        内存布局	    单块连续内存	                分段数组结构
        插入/删除效率	 尾部操作快，头部和中间操作慢	    头尾操作都快
            --> vector 頭部插入，非常耗時
            --> deque 頭部插入數值，為 常數時間 O(1)
        随机访问	    支持，通过索引访问，效率高	       支持，通过索引访问，效率稍逊于 vector
        使用场景	    动态数组，多用于 "末尾操作"	      双端操作，如缓存队列、滑动窗口

    --> 隨機訪問意思是：透過下標 index 進行訪問。
    --> Question_01: 
        分段陣列結構？
    --> Question_02:
        Deque 沒有容量概念？ (vector 有 capacity 函數)
    
    5. 应用场景
        滑动窗口问题：

        在解决固定窗口范围内的最大值或最小值问题时，deque 的双端操作非常高效。
        
        缓存：可用于实现 LRU 缓存策略（Least Recently Used）。
        队列扩展：

        如果普通队列需要支持双端操作，deque 是理想选择。
*/

#include <iostream>
#include <vector>
// 引用 deque 函式庫
#include <deque>
using namespace std;

// 01 基本操作： Initialization 部分
int main() {
    // Initialization
    // 有 8 種初始化方法：

    // 1. Empty Deque
    deque<int> dq1;

    // 2. Deque of Size with default values(0 for int)
    deque<int> dq2(3);

    // 3. Deque of Size 3 with all values initialized to 10
    deque<int> dq3(3, 10);

    // 4. Deque initialized with a list of values
    deque<int> dq4 = {1, 2, 3, 4};

    // 5. Deque initialized with vector by using iteration
    vector<int> vec = {1, 2, 3, 4};
    deque<int> dq5(vec.begin(), vec.end());

    // 6. Deque initialized with array
    int array[] = {1, 2, 3, 4};
    deque<int> dq6(array, array + 4);

    // 7. Deque initialized by copy with other deque
    deque<int> test = {1, 2, 3, 4};
    deque<int> dq7(test);
        // test still exist

    // 8. Deque initialized by moving the resource from other deque
    deque<int> test_02 = {1, 2, 3, 4};
    deque<int> dq8(move(test_02));
        // test_02 of size is 0. 
}

// 02 基本操作：Insert to the back or front index
// #include <deque>
// #include <iostream>
// using namespace std;

// int main() {
//     // 初始化 deque
//     deque<int> dq = {10, 20, 30};

//     // 在尾部和头部插入
//     dq.push_back(40);  // 尾部插入
//     dq.push_front(5);  // 头部插入

//     // 访问头部和尾部元素
//     cout << "头部元素: " << dq.front() << endl; // 输出: 5
//     cout << "尾部元素: " << dq.back() << endl;  // 输出: 40

//     // 删除头部和尾部元素
//     dq.pop_front();
//     dq.pop_back();

//     // 遍历并打印元素
//     cout << "当前元素: ";
//     for (int x : dq) {
//         cout << x << " ";
//     }
//     cout << endl; // 输出: 10 20 30

//     return 0;
// }

// 03 基本操作：Insert or delete the node
// #include <deque>
// #include <iostream>
// using namespace std;

// int main() {
//     deque<int> dq = {10, 20, 30};

//     // 插入元素
//     dq.insert(dq.begin() + 1, 15); // 在第二个位置插入 15

//     // 删除元素
//     dq.erase(dq.begin() + 2);      // 删除第三个位置的元素

//     // 打印当前元素
//     cout << "当前元素: ";
//     for (int x : dq) {
//         cout << x << " ";
//     }
//     cout << endl; // 输出: 10 15 30

//     return 0;
// }


// 04 基本操作：隨機訪問
// #include <deque>
// #include <iostream>
// using namespace std;

// int main() {
//     deque<int> dq = {1, 2, 3, 4, 5};

//     // 随机访问
//     cout << "索引 2 的元素: " << dq[2] << endl;   // 输出: 3
//     cout << "索引 4 的元素: " << dq.at(4) << endl; // 输出: 5

//     // 修改指定位置元素
//     dq[2] = 10;

//     // 遍历 deque
//     cout << "修改后元素: ";
//     for (int x : dq) {
//         cout << x << " ";
//     }
//     cout << endl; // 输出: 1 2 10 4 5

//     return 0;
// }

// 05 基本操作：使用 resize 調整大小
// #include <deque>
// #include <iostream>
// using namespace std;

// int main() {
//     deque<int> dq = {1, 2, 3};

//     // 调整大小
//     dq.resize(5, 0); // 扩展到 5 个元素，新增元素为 0

//     // 打印结果
//     cout << "调整大小后的元素: ";
//     for (int x : dq) {
//         cout << x << " ";
//     }
//     cout << endl; // 输出: 1 2 3 0 0

//     return 0;
// }

// 06 基本操作：交換兩個 deque
// #include <deque>
// #include <iostream>
// using namespace std;

// int main() {
//     deque<int> dq1 = {1, 2, 3};
//     deque<int> dq2 = {4, 5, 6};

//     // 交换内容
//     dq1.swap(dq2);

//     // 打印结果
//     cout << "dq1: ";
//     for (int x : dq1) {
//         cout << x << " ";
//     }
//     cout << endl; // 输出: 4 5 6

//     cout << "dq2: ";
//     for (int x : dq2) {
//         cout << x << " ";
//     }
//     cout << endl; // 输出: 1 2 3

//     return 0;
// }


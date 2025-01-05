#include <iostream>
using namespace std;

/*
    C++ 中，需要了解 Stack 和  Queue 底層實踐原理，常見的問題如下：

Stack:
    1. C++ 中的 Stack 是什麼容器？
    2. 使用的 Stack 是哪一個版本？
    3. 使用的 STL 中的 Stack 是如何實現？
    4. Stack 是否有提供迭代器，來遍歷 Stack 空間？

    --> 探討之前，要知道 Stack 和 Queue 是 (C++ STL)裡面的兩個數據結構。

    一一解答上述問題：
    1. C++ 中的 Stack 是什麼容器？
    ANS:
        1.Stack 是以底層容器完成所有工作，對外提供統一的接口。但是，底層容器可以插拔。
            --> 換句話說，我們可以控制使用哪一種容器來實現 Stack 的功能。
        2. 因此， STL 中，Stack 往往不歸類為 Container，反而稱作 Container Adapter。


    2. 使用的 Stack 是哪一個版本？
    ANS: 
        共有三個版本：
        1. HP STL 其他版本的 C++ STL，一般是以 HP STL 為藍本實踐出來，HP STL是 C++ 第一個實踐的版本。
        --> 程式碼是開源的。
        2. P.J.Plauger STL 由 P.J.Plauger 參照 HP STL 實現出來，被 Visual C++ Complier 採用。
        --> 非開源。
        3. SGI STL 由 Silicon Graphics Computer Systems 公司參照 HP STL 實現，被 Linux C++ Complier GCC 採用。
        --> SGI STL 是開源，原碼可讀性高。

    3. 使用的 STL 中的 Stack 是如何實現？
    ANS:
        問題 3 為 問題 1 的延伸。
        --> Stack 的底層，可由 vector、list、dequeue 實踐
        --> 默認情況下，SGI STL 以 dequeue 實踐
            --> Ex: Stack 也可以由 vector 底層實踐（抽拔概念）
            std::stack<int, std::vector<int>> third;

    
    4. Stack 是否有提供迭代器，來遍歷 Stack 空間？
    ANS:
        Stack：
        1. 為 LIFO (Last In First Out)
        2. 提供兩種接口 Push(放入數據)、Pop(移除數據)和 Top
            --> Time Complexity O(1)
        3. 不提供遍歷功能 (Iterator)
            --> ps. Set 和 Map 提供
Queue:
    邏輯與 Stack 完全一樣！上述問題，可以全部換成 Queue 回答。
*/


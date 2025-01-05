/*
    1. 為什麼需要 std:: 前綴？
        C++ 標準庫中的所有內容都在 std 命名空間中定義。這樣的設計是為了避免名字衝突。
        如果不使用命名空間，標準庫中的類型和函數，可能會與使用者自定義的類型和函數發生衝突！

        因此 #include<unordered_set> 僅僅只是引入頭文件，還需要使用特定命名空間來讓電腦區分。

        如果，使用者不介意命名空間污染(標準庫及自定義衝突)，可以使用 using namespace std; 此為通用寫法。
       
        用法	              示例	                   描述
        访问全局变量	       ::x	                     访问全局变量（当局部变量同名时）。
        访问命名空间中的成员    std::cout	              访问 std 命名空间中的 cout。
        访问类的静态成员	    ClassName::member	      访问类的静态成员变量或静态函数。
        定义类外的成员函数	    ClassName::functionName	  定义类的成员函数。
        访问枚举类的成员	    EnumClass::Member	     访问枚举类的成员。

    2. :: 和 : 的差異？

    -   ::  是範圍運算解析符號

    -   :   冒號運算符號

    當局部變量與全局變量同名時，可以使用 :: 來訪問全局變量。可以參考下面例子

*/

// 1. 访问全局变量
// #include <iostream>
// using namespace std;

// int x = 10; 

// int main() {
//     // 局部变量
//     int x = 20; 
//     cout << "局部变量 x: " << x << endl;    // 输出 20
//     cout << "全局变量 x: " << ::x << endl; // 使用 `::` 访问全局变量，输出 10
//     return 0;
// }

// 2. 访问命名空间中的成员

// #include <iostream>
// namespace A {
//     int x = 100;
//     void display() {
//         std::cout << "A::display() 被调用" << std::endl;
//     }
// }

// int main() {
//     std::cout << "命名空间 A 的 x: " << A::x << std::endl; // 访问 A 命名空间的 x
//     A::display(); // 调用 A 命名空间中的 display 函数
//     return 0;
// }
    // [結果]：
    
    /*
        命名空间 A 的 x: 100
        A::display() 被调用
    */

// 3. 访问类的静态成员
    // 访问类的静态成员变量或静态函数。
    // 定义类外的成员函数。
// #include <iostream>
// class Test {
// public:
//     static int x; // 静态成员变量
//     static void show() { // 静态成员函数
//         std::cout << "静态变量 x: " << x << std::endl;
//     }
// };

// int Test::x = 42; // 使用 :: 定义静态成员变量

// int main() {
//     Test::show(); // 使用 :: 调用静态成员函数
//     return 0;
// }

    // [結果]：
    
    /*
        静态变量 x: 42
    */

// 4. 用于枚举类
#include <iostream>
enum class Color { Red, Green, Blue };

int main() {
    Color c = Color::Red;
    if (c == Color::Red) {
        std::cout << "Color is Red" << std::endl;
    }
    return 0;
}

    // [結果]：
    
    /*
        Color is Red
    */
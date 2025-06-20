/*
字典 strList 中从字符串 beginStr 和 endStr 的转换序列是一个按下述规格形成的序列：

序列中第一个字符串是 beginStr。

序列中最后一个字符串是 endStr。

每次转换只能改变一个位置的字符（例如 ftr 可以转化 fty ，但 ftr 不能转化 frx）。

转换过程中的中间字符串必须是字典 strList 中的字符串。

beginStr 和 endStr 不在 字典 strList 中

字符串中只有小写的26个字母

给你两个字符串 beginStr 和 endStr 和一个字典 strList，找到从 beginStr 到 endStr 的最短转换序列中的字符串数目。如果不存在这样的转换序列，返回 0。

输入描述

第一行包含一个整数 N，表示字典 strList 中的字符串数量。 第二行包含两个字符串，用空格隔开，分别代表 beginStr 和 endStr。 后续 N 行，每行一个字符串，代表 strList 中的字符串。

输出描述

输出一个整数，代表从 beginStr 转换到 endStr 需要的最短转换序列中的字符串数量。如果不存在这样的转换序列，则输出 0。

输入示例

6
abc def
efc
dbc
ebc
dec
dfc
yhn
输出示例

4

提示信息

从 startStr 到 endStr，在 strList 中最短的路径为 abc -> dbc -> dec -> def，所以输出结果为 4

数据范围：

2 <= N <= 500
*/


#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
    public:

    private:

};


int main() {

    // Initialize the number of string
    int numString = 0;
    std::cin >> numString;
    // Initialize the beginString
    std::string beginStr, endStr, str;
    std::cin >> beginStr >> endStr;
    
    // Using a unorder_set to store the strList
    std::unordered_set <std::string> strList;
    for(int i = 0; i < numString; i++) {
        std::cin >> str;
        strList.insert(str);
    }

    // Import the Solution Class
    Solution sol;
    

    return 0;
}


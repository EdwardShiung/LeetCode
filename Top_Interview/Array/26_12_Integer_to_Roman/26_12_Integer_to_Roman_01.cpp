#include <iostream>
using namespace std;

/*

Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 

Constraints:

1 <= num <= 3999


- 3794

MMM = 3000
DCC = 700
XC = 90
IV = 4


*/




class Solution {
public:
    string intToRoman(int num) {

        // Store answer to the result
        string result = "";

        for(const auto& [value, symbol] : valueSchema) {
            if(num == 0) break;

            while(num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;

    }
private:
    vector<pair<int, string>> valueSchema{
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
    };
    // unordered_map<int, string> valueSchema = {
    //     {1000, "M"},
    //     {900, "CM"},
    //     {500, "D"},
    //     {400, "CD"},
    //     {100, "C"},
    //     {90, "XC"},
    //     {50, "L"},
    //     {40, "XL"},
    //     {10, "X"},
    //     {9, "IX"},
    //     {5, "V"},
    //     {1, "I"}
    // };
};


int main() {


    Solution solution;

    string result = solution.intToRoman(3749);
    cout << result << endl;


    //     unordered_map<int, string> valueSchema = {
    //     {1000, "M"},
    //     {900, "CM"},
    //     {500, "D"},
    //     {400, "CD"},
    //     {100, "C"},
    //     {90, "XC"},
    //     {50, "L"},
    //     {40, "XL"},
    //     {10, "X"},
    //     {9, "IX"},
    //     {5, "V"},
    //     {1, "I"}
    // };

    // for(const auto& [value, symbol]: valueSchema) {
    //     cout << "Value: " << value << " Symbol: " << symbol << endl;
    // }
}



/*
這兩種寫法都用來將整數對應到羅馬數字符號，但它們使用了不同的數據結構，並且在使用場景和性能方面有所不同。

### 差異分析

1. **數據結構類型**：
   - **`vector<pair<int, string>>`**：這是一個有序的數組，包含 `pair` 結構。`vector` 保持插入元素的順序，並且支持通過索引高效地訪問元素。
   - **`unordered_map<int, string>`**：這是一個哈希表，無序存儲 `key-value` 對。它提供了常數時間複雜度的查找和插入操作，但不保證元素的順序。

2. **查找效率**：
   - **`vector<pair<int, string>>`**：如果需要查找某個值，你可能需要線性遍歷整個 `vector`（時間複雜度為 `O(n)`）。但如果你需要按特定順序遍歷所有元素，`vector` 是合適的選擇。
   - **`unordered_map<int, string>`**：提供常數時間複雜度的查找操作（`O(1)`）。這在頻繁查找的情況下效率更高，但元素順序是無序的。

3. **使用場景**：
   - **`vector<pair<int, string>>`**：適用於需要保持順序並按順序遍歷的情況，比如這個例子中，你需要從最大的數字開始，依次嘗試匹配對應的羅馬數字符號。
   - **`unordered_map<int, string>`**：適用於需要快速查找 `key` 的情況，但不在意元素順序。

### 為什麼用 `vector<pair<int, string>>`
在這個將整數轉換為羅馬數字的例子中，順序非常重要。你需要從最大的數字開始，一直到最小的數字，按順序進行匹配。`vector<pair<int, string>>` 保證了這個順序，並且在順序遍歷時非常方便和高效。

### 為什麼不用 `unordered_map<int, string>`
`unordered_map` 的優勢在於快速查找，但在這個轉換問題中，你不需要通過 `key` 進行隨機訪問，而是需要按順序遍歷所有元素，因此 `unordered_map` 並不適合這種場景。

### 總結
- **`vector<pair<int, string>>`**：適合需要按順序進行遍歷的情況，如將數字轉換為羅馬數字。
- **`unordered_map<int, string>`**：適合需要快速查找的情況，但不在意順序。

因此，為了正確地將整數轉換為羅馬數字，應使用 `vector<pair<int, string>>`，以便保留正確的順序。




*/
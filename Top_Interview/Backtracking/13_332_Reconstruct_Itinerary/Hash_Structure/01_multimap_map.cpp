#include <iostream>
#include <set>
using namespace std;
int main() {
    unordered_map<string, multiset<string>> targets;

    // 假設JFK機場有三個航班，兩個飛往LAX，一個飛往SFO
    targets["JFK"].insert("LAX");
    targets["JFK"].insert("LAX");
    targets["JFK"].insert("SFO");

    // 遍歷並刪除飛往LAX的航班
    for (auto it = targets["JFK"].begin(); it != targets["JFK"].end();) {
        if (*it == "LAX") {
            it = targets["JFK"].erase(it); // 刪除元素並獲取新迭代器
        } else {
            ++it; // 只在未刪除時才遞增迭代器
        }
    }

    // 打印結果
    for (const auto& destination : targets["JFK"]) {
        cout << destination << " "; // 這裡應該只剩下"SFO"
    }
}
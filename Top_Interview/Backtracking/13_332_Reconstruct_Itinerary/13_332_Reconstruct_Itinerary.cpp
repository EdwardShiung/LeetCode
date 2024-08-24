#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

    [Question]:
    You are given a list of airline tickets where tickets[i] = 
    [fromi, toi] represent the departure and the arrival airports of one flight. 
    Reconstruct the itinerary in order and return it.

    All of the tickets belong to a man who departs from "JFK", thus, 
    the itinerary must begin with "JFK". If there are multiple valid itineraries, 
    you should return the itinerary that has the smallest lexical order when read as a single string.

    For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    You may assume all tickets form at least one valid itinerary. 
    You must use all the tickets once and only once.

    

    Example 1:

    Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    Output: ["JFK","MUC","LHR","SFO","SJC"]

    Example 2:

    Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
    Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] 
    but it is larger in lexical order.


    [Thought]:
    1. 如果沒處理好，死循環就沒辦法解決
    2. 字母順序，要如何映射？
    3. 使用回朔，“終止條件”是什麼？

    以題目舉例：
        example: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
        JFK -> MUC
        MUC -> LHR
        LHR -> SFO
        SFO -> SJC

        因此，終止條件為： 遇到的機場個數 = 航班數量 + 1


    4. 當 機場需要重複使用時，產生 一對多問題，如何映射？

    這部分要想好，有序排列，要如何用 hashmap 去做紀錄。
        --> 須了解 unordered_map、map、multimap
                  unordered_set、set、multiset 差異

    因為知道從 JFK 機場出發，但有可能又會回到 JFK，所以機場有可能重複使用
        --> 一對多，使用 unordered_map


    所以：

    1. unordered_map<string, multiset<string>> targets：

    這是一個哈希表，它的鍵（key）是出發機場的名稱（類型為 string）。
    它的值（value）是一個多重集合（multiset<string>），
    存儲了從這個出發機場到達的所有目的機場的名稱（類型為 string）。
    因為使用了 multiset，所以即使有 "多個航班" 到同一個目的地機場，
    這些目的地機場的名稱也會被記錄多次。

    例如：
    unordered_map<string, multiset<string>> targets;
    targets["JFK"].insert("LAX");
    targets["JFK"].insert("LAX");
    targets["JFK"].insert("SFO");

    在這個例子中，targets["JFK"] 
    將會包含 "LAX", "LAX", "SFO"，表示從 JFK 出發有兩班航班飛往 LAX，一班飛往 SFO。

    2. unordered_map<string, map<string, int>> targets：

    這是一個哈希表，它的鍵（key）是出發機場的名稱（類型為 string）。
    它的值（value）是一個映射（map<string, int>），
    其中鍵（key）是目的機場的名稱（類型為 string），值（value）是到達該目的機場的航班次數（類型為 int）。

    unordered_map<string, map<string, int>> targets;
    targets["JFK"]["LAX"] = 2;
    targets["JFK"]["SFO"] = 1;

    在這個例子中，targets["JFK"]["LAX"] 的值是 2，
    表示從 JFK 出發有兩班航班飛往 LAX，
    而 targets["JFK"]["SFO"] 的值是 1，表示有一班航班飛往 SFO。


    上述(1)和(2)，我選擇 (2)。因為，multiset 遍歷的時候，不能刪除元素，一但刪除元素，迭代器就無法使用。
    
    Q: 為什麼要刪除 multiset 裡面的元素呢？
    ANS: "出發機場" 和 "到達機場" 可能會重複，一但重複，並且沒刪除，就會進入死循環。

    因此，unordered_map<string, map<string, int>> targets
        --> 利用裡面的 map 標記 到達機場 及 航班次數
        --> unordered_map<出發機場, map<到達機場, 航班次數>
            --> 利用遞歸和回溯的方式，去查看：
                --> 如果航班次數大於 0，說明目的地還可以飛
                --> 如果航班次數小於 0，說明目的地不能飛了
                    --> 解決了對 multiset 做刪除元素和增加元素的操作
                        --> 相等於：不用刪除元素，只做標記

    
*/


class Solution {
private:
    // 定義 unordered_map<string, map<string, int>> target
    unordered_map<string, map<string, int>> targets;
    // Create a results
    vector<string> results;
    bool backtracking(int ticketNum, vector<string>& tickets) {
        // 終止條件：遇到的機場個數 = 航班數量 + 1
        if(results.size() == ticketNum + 1) {
            return true;
        }
        // 單層邏輯：
        for(pair<const string, int>& target: targets[results[results.size() - 1]]) {
            // 紀錄機場是否飛過
            if(target.second > 0) {
                results.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum, results)) return true;
                results.pop_back();
                target.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 紀錄映射關係：
        for(const vector<string>& vec: tickets) {
            //紀錄映射
            targets[vec[0]][vec[1]]++;
        }
        // 起始機場：題目要求 JFK
        results.push_back("JFK");
        backtracking(tickets.size(), results);
        return results;
    }
};


int main() {
    
    vector<vector<string>> tickets;
    tickets.push_back({"MUC","LHR"});
    tickets.push_back({"JFK","MUC"});
    tickets.push_back({"SFO","SJC"});
    tickets.push_back({"LHR","SFO"});

    Solution solution;

    vector<string> results = solution.findItinerary(tickets);

    for(string airport: results) {
        cout << airport << " ";
    }
    cout << endl;

    return 0;
}
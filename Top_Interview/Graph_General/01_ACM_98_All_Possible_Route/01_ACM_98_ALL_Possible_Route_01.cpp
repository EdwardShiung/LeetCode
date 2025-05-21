/*
题目描述】

给定一个有 n 个节点的"有向无环图"，节点编号从 1 到 n。
请编写一个函数，找出并返回所有从节点 1 到节点 n 的路径。
每条路径应以节点编号的列表形式表示。

【输入描述】

第一行包含两个整数 N，M，表示图中拥有 N 个节点，M 条边

后续 M 行，每行包含两个整数 s 和 t，表示图中的 s 节点与 t 节点中有一条路径

【输出描述】

输出所有的可达路径，路径中所有节点的后面跟一个空格，每条路径独占一行，存在多条路径，路径输出的顺序可任意。

如果不存在任何一条路径，则输出 -1。

注意输出的序列中，最后一个节点后面没有空格！ 例如正确的答案是 1 3 5,而不是 1 3 5， 5后面没有空格！

【输入示例】
5 5
1 3
3 5
1 2
2 4
4 5
【输出示例】
1 3 5
1 2 4 5 


用例解释：

有五个节点，其中的从 1 到达 5 的路径有两个，分别是 1 -> 3 -> 5 和 1 -> 2 -> 4 -> 5。

因为拥有多条路径，所以输出结果为：

1 3 5
1 2 4 5
或

1 2 4 5
1 3 5
都算正确。

数据范围：

图中不存在自环
图中不存在平行边
1 <= N <= 100
1 <= M <= 500
#
*/


#include <iostream>
#include <vector>
#include <list>
using namespace std;

//收集符合條件的路徑
vector<vector<int>> results;
// 蒐集單一一條路徑到 節點 n
vector<int> path;

// Step_01
// x 代表目前遍歷的節點
// n 終點
// graph 存當前的圖
void dfs(const vector<list<int>>& graph, int x, int n) {
    // Step_02: 終止條件
    // 當前節點 x 到達終點 n
    if(x == n) {
        results.push_back(path);
        return;
    }

    // 遍歷 x 節點，所有連接的節點
    for (int i : graph[x]) { // 找到 X 指向的節點
        path.push_back(i); // 遍歷到的節點加入到路徑中來
        dfs(graph, i, n); // 進入下一層遞歸
        path.pop_back(); // 回溯，撤銷本節點
    }
}


int main() {
    // 初始化 graph
        // n 為節點
        // m 為邊
        // 因為要先輸入幾個節點 (n)，再次輸入幾條邊 (m)
        // 接著，依序輸入的，會是每次節點每次節點的值
        // 因為每一條邊，會有兩個節點，所以一次都是輸入兩個整數 s 和 t
    int n, m, s, t;

    // 先輸入節點、邊
    cin >> n >> m;

    // [儲存方式]
    // 1. 利用 Adjacency Matrix 作為儲存格，並初始化裡面的值
    // 根據題目，值從 1 到 n，因此，陣列大小 n + 1
    // vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0))

    // while(m--) {
    //     cin >> s >> t;
    //     // 使用 Adjacency Matrix 無線圖，所以用 "1" 表示這兩個整數是連接的！
    //     graph[s][t] = 1;
    // }

    // 2. 利用 Adjacency List 作為儲存的格式，並初始化
    // list 為 C++ 裡的鏈錶
    vector<list<int>> graph(n + 1);
    while(m--) {
        cin >> s >> t;
        // 這種方法，代表 s->t 連接
        graph[s].push_back(t);
    }

    // 無論什麼節點，已經是從 0 節點出發
    path.push_back(1);
    dfs(graph, 1, n);

    // 輸出結果
    if(results.size() == 0) cout << -1 << endl;
    for(const vector<int> &pa : results) {
        for(int i = 0; i < pa.size() - 1; i++) {
            cout << pa[i] << " ";
        }
        cout << pa[pa.size() - 1] << endl;
    }
}
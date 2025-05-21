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


class Solution {
    public:
    // Store the Results
    vector<vector<int>> results;
    //Store the Path
    vector<int> path;

    void dfs(const vector<list<int>>& graph, int start, int end) {
        // Termination Condition
        if(start == end) {
            results.push_back(path);
            return;
        }
        // Iterate through all choices (adjacent nodes)
        for(int nextNode: graph[start]) {
            // Process the node
            path.push_back(nextNode);
            // Recursive call
            dfs(graph, nextNode, end);
            // Backtrack (undo the choice)
            path.pop_back();
        }
    }
};


int main() {
    // n: node
    int n;
    // m: edge
    int m;

    cin >> n >> m;

    // Using the Adjacency List to store the graph
        // graph[0] is not used
        // graph[1] is the first node
        // graph[2] is the second node
        // graph[n] is the last node
    vector<list<int>> graph(n + 1);

    while(m--) {
        // s: start node
        // t: target node
        int s, t;
        cin >> s >> t;
        /**
         * This method means that s->t is connected
         */
        graph[s].push_back(t);
    }

    // Create an instance of the Solution class
    Solution solution;
    // Start DFS from node 1 to node n
    solution.path.push_back(1); // Start from node 1
    solution.dfs(graph, 1, n); // Start DFS from node 1 to node n

    // Results
    vector<vector<int>> results = solution.results;


    // Check if there are any paths found
    if(results.empty()){
        // No path found
        cout << -1 << endl;
    }else{
        // Output all paths
        for(const auto& path: results) {
            for(int i = 0; i < path.size(); i++) {
                cout << path[i];  
            }
            cout << endl;
        }
    }
}

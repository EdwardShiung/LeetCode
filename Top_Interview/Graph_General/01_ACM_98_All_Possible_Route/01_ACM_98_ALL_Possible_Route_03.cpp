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

// This class is used to find all paths from source to destination in a directed graph
// using Depth First Search (DFS) algorithm
class Solution {
   public:
    std::vector<std::vector<int>> findAllPaths(const std::vector<std::list<int>>& graph, int source, int destination) {
        results.clear();
        path.clear();
        path.push_back(source);
        dfs(graph, source, destination);
        return results;
    }

   private:
    // Store the Results
    std::vector<std::vector<int>> results;
    //Store the Path
    std::vector<int> path;

    void dfs(const std::vector<std::list<int>>& graph, int current, int destination) {
        // Termination Condition
        if(current == destination) {
            results.push_back(path);
            return;
        }
        // Iterate through all choices (adjacent nodes)
        for(int neighbor: graph[current]) {
            // Process the node
            path.push_back(neighbor);
            // Recursive call
            dfs(graph, neighbor, destination);
            // Backtrack (undo the choice)
            path.pop_back();
        }
    }
};

// Global function to readGraph and printGraph
/**
 * 1. 單一職責原則（SRP）
 * 2. 這個函數是用來讀取圖的結構，並返回一個圖的表示
 * 3. 便於重用與測試
 * 4. 這個函數的功能是獨立的，與其他函數無關
 * 5. 這樣的設計使得代碼更易於維護和擴展
 */
std::vector<std::list<int>> readGraph(int nodeCount, int edgeCount) {
    // Using the Adjacency List to store the graph
    // graph[0] is not used
    std::vector<std::list<int>> graph(nodeCount + 1);
    while(edgeCount--) {
        int from, to;
        std::cin >> from >> to;
        graph[from].push_back(to);
    }
    return graph;
}

void printGraph(const std::vector<std::vector<int>>& paths) {
    if(paths.empty()) {
        std::cout << -1 << std::endl;
    }else {
        for(const auto& path: paths) {
            for(int i = 0; i < path.size(); i++) {
                std::cout << path[i];
            }
            std::cout << std::endl;
        }
    }
}

// Main function to read input, process the graph and print the results
int main() {
    int nodeCount, edgeCount;
    std::cin >> nodeCount >> edgeCount;

    auto graph = readGraph(nodeCount, edgeCount);

    Solution solver;
    int source = 1, destination = nodeCount;
    auto paths = solver.findAllPaths(graph, source, destination);

    printGraph(paths);
}




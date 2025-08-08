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



// Get all path
std::vector<std::vector<int>> results;

// Get path
std::vector<int> path;

void dfs(const std::vector<std::list<int>>& graph, int start, int end)
{
    if(start == end)
    {
        results.push_back(path);
        return;
    }
    // 遍歷節點
    for(int i : graph[start])
    {
        std::cout << "進入到 path " << i << " ";
        path.push_back(i);
        dfs(graph, i, end);
        // 在 pop_back 之前打印要删除的值
        std::cout << "回溯移除 path " << path.back() << " ";
        path.pop_back();
    }
}


int main(){
    
    int node = 0;
    int line = 0;
    int s;
    int t;


    // Step 01 input number of node and line
    std::cin >> node >> line;

    // Create a vector

    std::vector<std::list<int>> graph(node + 1);
    // Input value
    while(line--) 
    {
        std::cin >> s >> t;
        graph[s].push_back(t);
    }

    // // 測試 鄰接表 (這很重要！！)
    for(int i = 1; i <= node; i++)
    {
        std::cout << "Node" << i << " ";
        for(int neighbor : graph[i])
        {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
    /*
        Node1 3 2
        Node2 4
        Node3 5
        Node4 5
        Node5
     * 
     */

    // 無論什麼路徑，path 都從 1 開始
    path.push_back(1);
    dfs(graph, 1, node);


    // Print Results
    if(results.size() == 0) std::cout << -1 << std::endl;
    // for(const std::vector<int>& vec: results)
    // {   
    //     for(int i : vec) 
    //     {
    //         std::cout << i << " ";
    //     }
    //     std::cout << std::endl;
    // }
    
    return 0;
}

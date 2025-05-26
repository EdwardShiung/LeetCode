/**
 * 101. 孤岛的总面积
题目描述
给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿指的是由水平或垂直方向上相邻的陆地单元格组成的区域，且完全被水域单元格包围。
孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿。



现在你需要计算所有孤岛的总面积，岛屿面积的计算方式为组成岛屿的陆地的总数。

输入描述
第一行包含两个整数 N, M，表示矩阵的行数和列数。之后 N 行，每行包含 M 个数字，数字为 1 或者 0。
输出描述
输出一个整数，表示所有孤岛的总面积，如果不存在孤岛，则输出 0。
输入示例
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
输出示例
1
提示信息

在矩阵中心部分的岛屿，因为没有任何一个单元格接触到矩阵边缘，所以该岛屿属于孤岛，总面积为 1。



数据范围：

1 <= M, N <= 50。


[Thought]:

BFS solution
 *  file 01 這個做法不是很正確！本題“孤島”，強調：所有单元格都不接触边缘的岛屿！！並且，求“孤島”個數！
    因此，請看 file 02 BFS 正確做法！

    由於，題目強調，所有單元格都不接觸邊緣的島嶼，
    換言之，我是否可以先抓出邊緣四周為 "1" 且連接再一起的島嶼，再將他們變成 “0”。
    最後，再次計算孤島總面積 ("1" 沒有靠邊的島嶼)
 * 
 */

#include <iostream>

#define DIRECTION_COUNT 4

class Solution {
    public:
    
    // From left side and right side to search the island ("1")
    void leftToRight(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
        for(int i = 0; i < rowCount; i++) {
            if(graph[i][0] == '1') bfs(graph, i, 0);
            if(graph[i][colCount - 1]) bfs(graph, i, colCount - 1);
        }
    };

    // From top to bottom side to search the island ("1")
    void topToBottom(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
        for(int j = 0; j < colCount; j++) {
            if(graph[0][j] == '1') bfs(graph, 0, j);
            if(graph[rowCount - 1][j] == '1') bfs(graph, rowCount - 1, j);
        }
    };

    // Count the Isolated Island
    int countIsolatedIsland(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
        int count = 0;
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(graph[i][j] == '1') count++;
            }
        }
        return count;
    };

    private:
    // Coordinator of 4 directions
    int dir[DIRECTION_COUNT][2] = {
        {-1, 0},    //up
        {1, 0},     //down
        {0, -1},    //left
        {0, 1}      //right
    };

    void bfs(std::vector<std::vector<char>>& graph, int currRow, int currCol) {
        // Using a queue to assist 
        std::queue<std::pair<int, int>> que;
        que.push({currRow, currCol});
        // Once join the queue, we need to mark it!
        graph[currRow][currCol] = '0';
        while(!que.empty()) {
            std::pair<int, int> curr = que.front();
            que.pop();
            int currX = curr.first;
            int currY = curr.second;

            // Iterative around the cell
            for(int i = 0; i < DIRECTION_COUNT; i++) {
                int nextX = currX + dir[i][0];
                int nextY = currY + dir[i][1];
                // Limitation
                if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
                if(graph[nextX][nextY] == '1') {
                    que.push({nextX, nextY});
                    graph[nextX][nextY] = '0';
                }
            }
        }
    };
};


// Function: createGraph
std::vector<std::vector<char>> createGraph(int rowCount, int colCount) {
    
    // Create a 2D vector graph
    std::vector<std::vector<char>> graph(rowCount, std::vector<char>(colCount));
    // Loop to generate the graph
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0 ; j < colCount; j++) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
};

// Print the Graph
void printGraph(const std::vector<std::vector<char>>& graph) {
    for(const std::vector<char> row: graph) {
        for(const char cell: row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
   
    // Create a Graph
    std::vector<std::vector<char>> graph = createGraph(rows, cols);

    //Print the Graph
    printGraph(graph);

    // Calculate the Isolated Island
    Solution sol;
    sol.leftToRight(graph, rows, cols);
    sol.topToBottom(graph, rows, cols);
    int results = sol.countIsolatedIsland(graph, rows, cols);

    std::cout << results << std::endl;
    
    return 0;
};
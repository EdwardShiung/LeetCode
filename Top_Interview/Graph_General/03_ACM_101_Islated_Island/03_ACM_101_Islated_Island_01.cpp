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
 *  我這個做法不是很正確！本題“孤島”，強調：所有单元格都不接触边缘的岛屿！！
    因此，請看 file 02 BFS 正確做法！
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

#define DIRECTION_COUNT 4

class Solution {
    
    public:
    bool findIslatedIsland(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
        bool hasIslated = false;
        std::vector<std::vector<bool>> visited(rowCount, std::vector<bool>(colCount, false));
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(!visited[i][j] && graph[i][j] == '1') {
                    bfs(graph, visited, i, j, hasIslated);
                }
            }
        }
        return hasIslated;
    };

    private:
    // coordinator of 4 directions
    int dir[DIRECTION_COUNT][2] = {
        {-1, 0},    //up
        {1, 0},     //down
        {0, -1},    //left
        {0, 1},     //right
    };
    
    void bfs(std::vector<std::vector<char>>& graph, std::vector<std::vector<bool>>& visited, int currRow, int currCol, bool& hasIslated) {
        // Set a queue
        std::queue<std::pair<int, int>> que;
        que.push({currRow, currCol});
        // Record the visited
        visited[currRow][currCol] = true;

        while(!que.empty()) {
            // Get the current cell X and Y
            std::pair<int, int> curr = que.front();
            que.pop();

            // Get the current
            int currX = curr.first;
            int currY = curr.second;

            for(int i = 0; i < DIRECTION_COUNT; i++) {
                int nextX = currX + dir[i][0];
                int nextY = currY + dir[i][1];
                if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
                if(!visited[nextX][nextY] && graph[nextX][nextY] == '0') {
                    hasIslated = true;
                }
            }
        }
    };
};

// Create a Graph
std::vector<std::vector<char>> createGraph(int rowCount, int colCount) {
    std::vector<std::vector<char>> graph(rowCount, std::vector<char>(colCount));
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
};

// Print a Graph
void printGraph(std::vector<std::vector<char>>& graph) {
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

    // create a graph
    std::vector<std::vector<char>> graph = createGraph(rows, cols);

    //print a graph
    printGraph(graph);

    // Verified if islated island or not
    Solution sol;
    bool hasIalatedIsland = sol.findIslatedIsland(graph, rows, cols);

    // Print the result
    std::cout << hasIalatedIsland << std::endl;

}
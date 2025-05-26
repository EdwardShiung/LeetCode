/**
 * 
 * 
 * 100. 岛屿的最大面积
题目描述
给定一个由 1（陆地）和 0（水）组成的矩阵，计算岛屿的最大面积。岛屿面积的计算方式为组成岛屿的陆地的总数。岛屿由水平方向或垂直方向上相邻的陆地连接而成，并且四周都是水域。你可以假设矩阵外均被水包围。
输入描述
第一行包含两个整数 N, M，表示矩阵的行数和列数。后续 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。
输出描述
输出一个整数，表示岛屿的最大面积。如果不存在岛屿，则输出 0。
输入示例
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
输出示例
4
提示信息

样例输入中，岛屿的最大面积为 4。

数据范围：

1 <= M, N <= 50。
 * 
 * 
 * 
 * [Thought]:
 * 1. By using DFS, we can solve the problem.
 * 
 * 
 */




#include <iostream>
#include <vector>
#include <algorithm>

#define DIRECTION_COUNT 4

class Solution {
    public:
    int findMaximumArea(std::vector<std::vector<char>>& graph, int rowCount, int colCount){
        int areaMaximum = 0;
        std::vector<std::vector<bool>> visited(rowCount, std::vector<bool>(colCount, false));
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(!visited[i][j] && graph[i][j] == '1') {
                    int currentArea = 0;
                    dfs(graph, visited, i, j, currentArea);
                    areaMaximum = std::max(currentArea, areaMaximum);
                }
            }
        }
        return areaMaximum;
    };

    private:
    // Coordinator of 4 directions
    int dir[4][2] = {
        {-1, 0},    //up
        {1, 0},     //down
        {0, 1},     //right
        {0, -1},    //left
    };

    // DFS
    void dfs(std::vector<std::vector<char>>& graph, std::vector<std::vector<bool>>& visited, int currRow, int currCol, int& currArea) {
        for(int i = 0; i < DIRECTION_COUNT; i++) {
            int nextX = currRow + dir[i][0];
            int nextY = currCol + dir[i][1];
            if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
            if(!visited[nextX][nextY] && graph[nextX][nextY] == '1') {
                currArea++;
                visited[nextX][nextY] = true;
                dfs(graph, visited, nextX, nextY, currArea);
            }
        }
    };
};

// Build the Graph
std::vector<std::vector<char>> readGraph(int rowCount, int colCount) {
    std::vector<std::vector<char>> graph(rowCount, std::vector<char>(colCount));
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
};


// Print the Graph
void printGraph(const std::vector<std::vector<char>>& graph) {
    for(const std::vector<char> row: graph) {
        for(const char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    int rows, cols;
    std:: cin >> rows >> cols;

    // Read the Graph
    std::vector<std::vector<char>> graph = readGraph(rows, cols);

    // Print the Graph
    printGraph(graph);

    // Calculate the Maximum Area
    Solution sol;
    int results = sol.findMaximumArea(graph, rows, cols);

    // Print the results
    std::cout <<  results << std::endl;
}



/**
 * 1. int dir[4][2] --> 這種寫法為 C-style。如果要統一 C++，可以使用 std::array
 * --> std::array<std::pair<int, int>, DIRECTION_COUNT> directions = {{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};
 */
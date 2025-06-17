/**
 * 
 * 题目描述
给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿是被水包围，并且通过水平方向或垂直方向上相邻的陆地连接而成的。



你可以假设矩阵外均被水包围。在矩阵中恰好拥有一个岛屿，假设组成岛屿的陆地边长都为 1，请计算岛屿的周长。岛屿内部没有水域。

输入描述
第一行包含两个整数 N, M，表示矩阵的行数和列数。之后 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。
输出描述
输出一个整数，表示岛屿的周长。
输入示例
5 5
0 0 0 0 0 
0 1 0 1 0
0 1 1 1 0
0 1 1 1 0
0 0 0 0 0
输出示例
14
提示信息


岛屿的周长为 14。


数据范围：

1 <= M, N <= 50。
 * 
 */

#include <iostream>
#include <vector>

#define DIRECTION 4

class Solution {
    
    public:
        int calculatePerimeter(int rowCounts, int colCounts, std::vector<std::vector<int>>& graph) {
            // Initialize the result
            int result = 0;
            for(int i = 0; i < rowCounts; i++) {
                for(int j = 0; j < colCounts; j++) {
                    if(graph[i][j] == 1) {
                        for(int k = 0; k < DIRECTION; k++) {
                            int nextX = i + dir[k][0];
                            int nextY = j + dir[k][1];

                            // Calculate the Perimeter
                            if(nextX < 0 
                                || nextX >= graph.size() 
                                || nextY < 0 
                                || nextY >= graph[0].size() 
                                || graph[nextX][nextY] == 0) result++; 
                        }
                    }
                }
            }
            return result;
        };
    
    private:
        int dir[4][2] = {
            {-1, 0},    //Up
            {1, 0},     //Down
            {0, -1},    //Left
            {0, 1},     //Right 
        };


};

std::vector<std::vector<int>> createGraph(int rowCount, int colCount) {
    // Initialize the Graph by using vector
    std::vector<std::vector<int>> graph(rowCount, std::vector<int>(colCount));

    // Build the Graph
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
};

// Print the Graph
void printGraph(const std::vector<std::vector<int>>& graph) {
    for(const std::vector<int> row: graph) {
        for(const int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}


int main() {

    // Initialize the Rows & Cols
    int rows, cols;
    std::cin >> rows >> cols;

    // Create a Graph
    std::vector<std::vector<int>> graph = createGraph(rows, cols);

    // Initialize a Graph
    printGraph(graph);

    // Calculate the Perimeter
    Solution sol;

    int result = sol.calculatePerimeter(rows, cols, graph);

    // Print the result
    std::cout << result << std::endl;
    
    return 0;
}

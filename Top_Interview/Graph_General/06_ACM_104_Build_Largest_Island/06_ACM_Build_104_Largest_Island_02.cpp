/**
 * 104. 建造最大岛屿
题目描述
给定一个由 1（陆地）和 0（水）组成的矩阵，你最多可以将矩阵中的一格水变为一块陆地，在执行了此操作之后，
矩阵中最大的岛屿面积是多少。

岛屿面积的计算方式为组成岛屿的陆地的总数。岛屿是被水包围，并且通过水平方向或垂直方向上相邻的陆地连接而成的。
你可以假设矩阵外均被水包围。

输入描述
第一行包含两个整数 N, M，表示矩阵的行数和列数。之后 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。
输出描述
输出一个整数，表示最大的岛屿面积。
输入示例
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
输出示例
6
提示信息

对于上面的案例，有两个位置可将 0 变成 1，使得岛屿的面积最大，即 6。

数据范围：

1 <= M, N <= 50。
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Define Direction Count
#define DIRECTION_COUNT 4

class Solution {
    public:

    // Using the hashmap to record the area 
    std::unordered_map<int, int> recordArea;

    // Record the Area in hashmap for each block
    void recordMaxArea(std::vector<std::vector<int>>& graph, int rowCount, int colCount, std::unordered_map<int, int>& recordArea) {
        // Label the block by beginning number 2
        int label = 2;
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(graph[i][j] == 1) {
                    int countArea = 0;
                    dfs(graph, i, j, countArea, label);
                    recordArea[label] = countArea;
                    label++;
                }
            }
        }
    };

    // Find the Max Area
    int findMaxArea(std::vector<std::vector<int>>&graph, int rowCount, int colCount, std::unordered_map<int, int>& recordArea) {
        // Initialize Maximum
        int maxArea = 0;
        // Using the unordered_set to record the area
        std::unordered_set<int> setArea;
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(graph[i][j] == 0) {
                    // Re-calculate the area
                    int countArea = 1;
                    
                    for(int k = 0; k < DIRECTION_COUNT; k++) {
                        int nextRow = i + dir[k][0];
                        int nextCol = j + dir[k][1];
                        
                        if(nextRow >= 0 && nextRow < rowCount && nextCol >= 0 && nextCol < colCount && recordArea[graph[nextRow][nextCol]] && !setArea.count(graph[nextRow][nextCol])){
                            countArea = countArea + recordArea[graph[nextRow][nextCol]];
                            setArea.insert(graph[nextRow][nextCol]);
                        }
                    }
                    maxArea = countArea > maxArea ? countArea : maxArea;
                }

            }
        }
        return maxArea;
    };

    private:  

    // Initialize a dir
    int dir[DIRECTION_COUNT][2] = {
        {-1, 0},    // UP
        {1, 0},     // Down
        {0, -1},    // Left
        {0, 1},     // Right
    };

    // DFS 
    void dfs(std::vector<std::vector<int>>& graph, int currRow, int currCol, int& countArea, int& label) {
        graph[currRow][currCol] = label;
        countArea++;

        for(int i = 0; i < DIRECTION_COUNT; i++) {
            int nextRow = currRow + dir[i][0];
            int nextCol = currCol + dir[i][1];
            if(nextRow >= 0 && nextRow < graph.size() && nextCol >= 0 && nextCol < graph[0].size() && graph[nextRow][nextCol] == 1) {
                graph[nextRow][nextCol] = label;
                dfs(graph, nextRow, nextCol, countArea, label);
            }
        }
    }

};

std::vector<std::vector<int>> createGraph(int rowCount, int colCount) {
    // Initialize the Graph
    std::vector<std::vector<int>> graph(rowCount, std::vector<int>(colCount));

    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
};

void printGraph(const std::vector<std::vector<int>>& graph) {
    for(const std::vector<int> row : graph) {
        for(const int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    // Create a Graph
    std::vector<std::vector<int>> graph = createGraph(rows, cols);

    // Print the Graph
    printGraph(graph);

    // Call the solution class to deal with the Graph
    Solution sol;


    sol.recordMaxArea(graph, rows, cols, sol.recordArea);

    int result = sol.findMaxArea(graph, rows, cols, sol.recordArea);

    std::cout << result << std::endl;

    return 0;
};



 
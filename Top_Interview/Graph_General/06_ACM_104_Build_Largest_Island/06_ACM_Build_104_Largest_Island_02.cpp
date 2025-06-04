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


class Solution {
    
    public:
    // Step 01: Record the area of each island in the hashmap
    std::unordered_map<int, int> recordArea(std::vector<std::vector<int>>& graph, int rowCount, int colCount) {
         // Initialize a hashmap (key, area)
         std::unordered_map<int, int> areaRecord;
         // Start from 2 to differentiate from land (1) and water (0)
         int islandId = 2;
         for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(graph[i][j] == 1) {
                    int count = 0;
                    dfs(graph, i, j, islandId, count);
                    // Increment islandId for the next island
                    islandId++;
                }
            }
         }
         return areaRecord;
    };  

    // Step 02: Calcuate the area after flip the "0" cell to "1"
    int findLargestArea(std::vector<std::vector<int>>& graph) {
        
    }
    private:
    void dfs(std::vector<std::vector<int>>& graph, int currRow, int currCol, int& islandId, int& count) {

    }
};

// Create a Graph
std::vector<std::vector<int>> createGraph(int rowCount, int colCount) {
    // Initialize a graph
    std::vector<std::vector<int>> graph(rowCount, std::vector<int>(colCount));
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
};

// Print the Graph
void printGraph(const std::vector<std::vector<int>>& graph) {
    for(const std::vector<int> row : graph) {
        for(const int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
};


 int main () {
    
    // Initialize the rows and columns
    int rows, cols;
    std::cin >> rows >> cols;

    // Create a graph
    std::vector<std::vector<int>> graph = createGraph(rows, cols);

    return 0;
 }
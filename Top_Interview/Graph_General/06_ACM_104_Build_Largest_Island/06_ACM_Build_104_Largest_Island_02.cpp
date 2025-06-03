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
#include <algorithm>
#include <unordered_set>

#define DIRECTION_COUNT 4

class Solution {
    public:
    int buildMaxIsland(std::vector<std::vector<int>>& graph, int rowCount, int colCount) {
        // Using the visited record 
        std::vector<std::vector<int>> visited = graph;
        // Store all areas of islands
        std::vector<int> islandAreas;
        int maxArea = 0;

        // Step 01: Store each area of island
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(graph[i][j] == 1) {
                    int countArea = 0;
                    dfs(graph, i, j, countArea);
                    // std::cout << countArea << std::endl;
                    islandAreas.push_back(countArea);
                    //maxArea = std::max(maxArea, countArea);
                }       
            }
        }

        // Step 02: Convert each water cell to land and calculate the maximum area
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(visited[i][j] == 0) {
                    // Convert 0 to 1 (Convert water to land)
                    int newArea = 1;
                    std::unordered_set<int> connectedIslands;
                    for(int k = 0; k < DIRECTION_COUNT; k++) {
                        int nextX = i + dir[k][0];
                        int nextY = j + dir[k][1];

                        if(nextX < 0 || nextX >= rowCount || nextY < 0 || nextY >= colCount) continue;
                        if(graph[nextX][nextY] == -1) {
                            // 這部分非常不對！
                            std::cout << nextX * colCount + nextY << std::endl;
                            connectedIslands.insert(nextX * colCount + nextY);
                        }
                    }
                    // 這部分非常不好！
                    for(int island : connectedIslands) {
                        newArea += islandAreas[island];
                    }
                    maxArea = std::max(maxArea, newArea);
                }
            }
        }
        return maxArea;
    };
    private:
    int dir[DIRECTION_COUNT][2] = {
        {-1, 0},    //up
        {1, 0},     //down
        {0, -1},    //left
        {0, 1}      //right
    };
    void dfs(std::vector<std::vector<int>>& graph, int currRow, int currCol, int& countArea) {
        graph[currRow][currCol] = -1;
        countArea++;
        for(int i = 0; i < DIRECTION_COUNT; i++) {
            int nextX = currRow + dir[i][0];
            int nextY = currCol + dir[i][1];
            
            // Limitation
            if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
            if(graph[nextX][nextY] == 1) {
                dfs(graph, nextX, nextY, countArea);
            }
        }
    };
};


// Function: Create the Graph
std::vector<std::vector<int>> createGraph(int rowCount, int colCount) {
    // Initialize the graph
    std::vector<std::vector<int>> graph(rowCount, std::vector<int>(colCount));
    
    // for-loop to generate the graph
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            std::cin >> graph[i][j];
        }
    }

    return graph;
};

// Function: Print the Graph
void printGraph(const std::vector<std::vector<int>>& graph) {
    for(const std::vector<int> row : graph) {
        for(const int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    int rows, cols;
    std::cin >> rows >> cols;

    // Create the Graph
    std::vector<std::vector<int>> graph = createGraph(rows, cols);

    // Print the Graph
    printGraph(graph);

    // Calculate the results
    Solution sol;
    int results = sol.buildMaxIsland(graph, rows, cols);
    std::cout << results << std::endl;
    return 0;
}
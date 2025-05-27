/**
 * 102. 沉没孤岛
题目描述
给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿指的是由水平或垂直方向上相邻的陆地单元格组成的区域，且完全被水域单元格包围。孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿。

现在你需要将所有孤岛“沉没”，即将孤岛中的所有陆地单元格（1）转变为水域单元格（0）。

输入描述
第一行包含两个整数 N, M，表示矩阵的行数和列数。

之后 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。

输出描述
输出将孤岛“沉没”之后的岛屿矩阵。 注意：每个元素后面都有一个空格
输入示例
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
输出示例
1 1 0 0 0
1 1 0 0 0
0 0 0 0 0
0 0 0 1 1
提示信息

将孤岛沉没。

数据范围：

1 <= M, N <= 50。
 *
 *
 *  [Thought]:
 *  1. 使用 DFS 
 */


#include <iostream>
#include <vector>

#define DIRECTION_COUNT 4

class Solution {
    public:
    //Turn the '1' to '2' in the side of graph
    //Left & Right
    void leftToRight(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
        for(int i = 0; i < rowCount; i++) {
            if(graph[i][0] == '1') dfs(graph, i, 0);
            if(graph[i][colCount - 1] == '1') dfs(graph, i, colCount - 1);
        }
    };  
    // Top & Bottom
    void topToBottom(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
        for(int j = 0; j < colCount; j++) {
            if(graph[0][j] == '1') dfs(graph, 0, j);
            if(graph[rowCount - 1][j] == '1') dfs(graph, rowCount - 1, j);
        }
    };

    //Transfer the cell which has '1' to '0' and Printout
    void graphTransfer_01(std::vector<std::vector<char>>& graph) {
        for(std::vector<char>& row : graph) {
            for(char& cell : row) {
                if(cell == '1') cell = '0';
            }
        }
    };

    //Transfer the cell which has '2' to '1' and Printout
    void graphTransfer_02(std::vector<std::vector<char>>& graph) {
        for(std::vector<char>& row : graph) {
            for(char& cell : row) {
                if(cell == '2') cell = '1';
            }
        }
    };

    private:

    // Coordinator of 4 Directions
    int dir[DIRECTION_COUNT][2] = {
        {-1, 0},    //up
        {1, 0},     //down
        {0, -1},    //left
        {0, 1},     //right


        
    };

    // DFS
    void dfs(std::vector<std::vector<char>>& graph, int currRow, int currCol) {
        // Set the current cell to '2'
        graph[currRow][currCol] = '2';
        // Iterative the neighbors around the cell
        for(int i = 0;  i < DIRECTION_COUNT; i++) {
            int nextX = currRow + dir[i][0];
            int nextY = currCol + dir[i][1];

            // Limitation
            if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
            if(graph[nextX][nextY] == '1'){
                graph[nextX][nextY] = '2';
                dfs(graph, nextX, nextY);
            }
        }
    }
};

// Function to Create a Graph
std::vector<std::vector<char>> createGraph(int rowCount, int colCount) {
    // Initialized a Graph
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
    for(const std::vector<char> row : graph) {
        for(const char cell : row) {
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

    // Print a Graph
    std::cout << "Initialized a Graph: " << std::endl;
    printGraph(graph);
    //Transfer '1' to '2'
    std::cout << "Transfer '1' to '2'" << std::endl;
    Solution sol;
    sol.leftToRight(graph, rows, cols);
    sol.topToBottom(graph, rows, cols);
    printGraph(graph);
    //Transfer '1' to '0'
    std::cout << "Transfer '1' to '0'" << std::endl;
    sol.graphTransfer_01(graph);
    printGraph(graph);
    // Transfer '2' to '1'
    sol.graphTransfer_02(graph);
    std::cout << "Transfer '2' to '1'" << std::endl;
    printGraph(graph);
    return 0;
}
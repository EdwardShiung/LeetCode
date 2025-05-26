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
 * 1. By using BFS, we can solve the problem.
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

class Solution {
    public:
    int findMaximumArea(std::vector<std::vector<char>>& graph, int rowCount, int colCount){
        int areaMaximum = 0;
        std::vector<std::vector<bool>> visited(rowCount, std::vector<bool>(colCount, false));
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(!visited[i][j] && graph[i][j] == '1') {
                    int currentArea = 0;
                    bfs(graph, visited, i, j, currentArea);
                    areaMaximum = std::max(areaMaximum, currentArea);
                }
            }
         }
         return areaMaximum;
    };  


    private:
    // Coordinate of 4 direction
    int dir[4][2] = {
        {-1, 0},    //up
        {1, 0},     //down
        {0, 1},     //right
        {0, -1}     //left
    };

    void bfs(std::vector<std::vector<char>>& graph, std::vector<std::vector<bool>>& visited, int curRow, int curCol, int& currentArea) {
        // Set a queue to assist iteration
        std::queue<std::pair<int, int>> que;
        // Place the current cell to queue
        que.push({curRow, curCol});
        // Once place the current cell to queue, we should record.
        visited[curRow][curCol] = true;
        // Iterative the graph
        while(!que.empty()) {
            // Add the area first
            currentArea++;
            // Get the cell (each cell has X and Y)
            std::pair<int, int> cur = que.front();
            // pop out the front elements
            que.pop();
            // Get the current cell X and Y
            // X coordinator of cell
            int currX = cur.first;
            int currY = cur.second;
            // Loop around the cell
            for(int i = 0; i < 4; i++) {
                int nextX = currX + dir[i][0];
                int nextY = currY + dir[i][1];

                if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
                if(!visited[nextX][nextY] && graph[nextX][nextY] == '1') {
                    que.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }
    };
};

// Read Graph
std::vector<std::vector<char>> readGraph(int rows, int columns) {
    
    // Graph Initialize
    std:: vector<std::vector<char>> graph(rows, std::vector<char>(columns));
    // Using the for-loop to generate the graph
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
};

// Print Graph
void printGraph(const std::vector<std::vector<char>>& graph) {

    for(const std::vector<char> row: graph) {
        for(const char cell: row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
};  

int main() {
    // Size of Graph
    int rows, cols;
    // Input the size of Graph
    std::cin >> rows >> cols;

    // Create a Graph by rows and cols
    std::vector<std::vector<char>> graph = readGraph(rows, cols); 

    // Print the Graph
    printGraph(graph);

    // Calculate the Island
    Solution sol;
    int results = sol.findMaximumArea(graph, rows, cols);

    //Print the Results
    std::cout << results << std::endl;

    return 0;
}




/**
 * 1. 小心要初始化，避免造成不必要的 segmentation fault
 * std:: vector<std::vector<char>> graph(rows, std::vector<char>(columns));
 * 
 * 2. 方位：(row, col) ==> 與學習數學坐標系的 (x,y) 不同 ==> (y, x)
 * 
 * 3. 了解傳值和傳址的差異
 * void bfs(int& currentArea) --> 不用製造多餘的空間，改變原來的變數值(透過傳遞地址，改變變數值)
 * 
 * 4. 了解如何使用 std::max --> 庫 #include<algorithm>
 *      --> 比較時，利用 curVal vs maxVal
 *      --> curVal 為動態
 */
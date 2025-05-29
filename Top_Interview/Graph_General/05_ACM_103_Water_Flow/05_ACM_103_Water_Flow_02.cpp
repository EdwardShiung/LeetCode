/**
 * 103. 水流问题
题目描述
现有一个 N × M 的矩阵，每个单元格包含一个数值，这个数值代表该位置的相对高度。
矩阵的左边界和上边界被认为是第一组边界，而矩阵的右边界和下边界被视为第二组边界。

矩阵模拟了一个地形，当雨水落在上面时，水会根据地形的倾斜向低处流动，
但只能从较高或等高的地点流向较低或等高并且相邻（上下左右方向）的地点。
我们的目标是确定那些单元格，从这些单元格出发的水可以达到第一组边界和第二组边界。

输入描述
第一行包含两个整数 N 和 M，分别表示矩阵的行数和列数。 

后续 N 行，每行包含 M 个整数，表示矩阵中的每个单元格的高度。

输出描述
输出共有多行，每行输出两个整数，用一个空格隔开，表示可达第一组边界和第二组边界的单元格的坐标，输出顺序任意。
输入示例
5 5
1 3 1 2 4
1 2 1 3 2
2 4 7 2 1
4 5 6 1 1
1 4 1 2 1
输出示例
0 4
1 3
2 2
3 0
3 1
3 2
4 0
4 1
提示信息

图中的蓝色方块上的雨水既能流向第一组边界，也能流向第二组边界。所以最终答案为所有蓝色方块的坐标。 


数据范围：

1 <= M, N <= 100。
 * 
 * 
 * [Thought]
 * 1. 題目要找到，哪些格子，可以到達第一邊界（左邊和上邊），並且也可以到達第二邊界（右邊和下邊）。
 * 這題可以用 BFS、DFS或並查集來解決！
 * 2. 本題思路就是：水由低處流向高處，找尋至高點。因此，分別從第一邊界和第二邊界，找尋交集！！
 * 3. 本題使用 DFS
 */

#include <iostream>
#include <vector>

#define DIRECTION_COUNT 4

class Solution {
    public:
    void isResults(std::vector<std::vector<int>>& graph, int rowCount, int colCount) {

        // 利用兩個 graph 做記錄 (Two Visited Board) 當交集情況下，代表找到制高點 
        // 第一個版： left and top side
        // 第二個版： right and bottom 
        // First Board
        std::vector<std::vector<bool>> firstBoarder(rowCount, std::vector<bool>(colCount, false));
        // Second Board
        std::vector<std::vector<bool>> secondBoard(rowCount, std::vector<bool>(colCount, false));

        // For loop in first board
        for(int i = 0; i < rowCount; i++) {
            //left
            dfs(graph, firstBoarder, i, 0);
            //right
            dfs(graph, secondBoard, i, colCount - 1);
        }

        // For loop in second board
        for(int j = 0; j < colCount; j++) {
            //top
            dfs(graph, firstBoarder, 0, j);
            //bottom
            dfs(graph, secondBoard, rowCount - 1, j);
        }

        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(firstBoarder[i][j] && secondBoard[i][j]) {
                    std::cout << i << " " << j << std::endl;
                }
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
    void dfs(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited, int currRow, int currCol) {
        if (visited[currRow][currCol]) return;
    
        visited[currRow][currCol] = true;
    
        for (int i = 0; i < 4; i++) {
            int nextX = currRow + dir[i][0];
            int nextY = currCol + dir[i][1];
            if (nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
            if (graph[currRow][currCol] > graph[nextX][nextY]) continue; // 注意：这里是从低向高遍历
    
            dfs (graph, visited, nextX, nextY);
        }
        return;
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
}

int main() {
    // initialize rows and cols
    int rows, cols;
    std::cin >> rows >> cols;

    // Create the Graph
    std::vector<std::vector<int>> graph = createGraph(rows, cols);
    // Print the Graph
    printGraph(graph);
    
    // Get the result
    Solution sol;
    sol.isResults(graph, rows, cols);
    return 0;
}

/*
 * 
 * 時間複雜度計算
 * 
 * 1. isResults 函式
 * 
 * 時間複雜度：O((rowCount + colCount) * rowCount*colCount)
 * 
 * 
 */
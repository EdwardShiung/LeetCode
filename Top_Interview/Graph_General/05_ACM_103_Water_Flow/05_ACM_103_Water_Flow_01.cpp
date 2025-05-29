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
 * 2. 本題用 DFS 
 */

#include <iostream>
#include <vector>

#define DIRECTION_COUNT 4

class Solution {
    public:
    bool isResult(std::vector<std::vector<int>>& graph, int currRow, int currCol, int rowCount, int colCount) {

        // By using a visited graph to record the results
        std::vector<std::vector<bool>> visited(rowCount, std::vector<bool>(colCount, false));

        // using the dfs to iterate the process
        dfs(graph, visited, currRow, currCol);
        // Each cell should touch first and second boundary
        bool isFirst = false;
        bool isSecond = false;

        // First boundary is left and upper side
        // Left Side
        for(int i = 0; i < rowCount; i++) {
            if(visited[i][0]) {
                isFirst = true;
                break;
            }
        }

        // Upper Side
        for(int j = 0; j < colCount; j++) {
            if(visited[0][j]) {
                isFirst = true;
                break;
            }
        }

        // Second boundary is right and bottom side
        // Right Side
        for(int k = 0; k < rowCount; k++) {
            if(visited[k][colCount - 1]) {
                isSecond = true;
                break;
            }
        }

        // Bottom Side
        for(int l = 0; l < colCount; l++) {
            if(visited[rowCount - 1][l]) {
                isSecond = true;
                break;
            }
        }

        // Results
        if(isFirst && isSecond) {
            std::cout << currRow << " " << currCol << std::endl;
            return true;
        }
        return false;
    };


    private:
    // Coordinator of 4 Directions
    int dir[DIRECTION_COUNT][2] = {
        {-1, 0},    //up
        {1, 0},     //down
        {0, -1},    //left
        {0, 1}      //right
    };

    // DFS
    void dfs(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited, int currRow, int currCol) {
        // Make sure if the cell has been visited
        if(visited[currRow][currCol]) return;
        // Mark the cell
        visited[currRow][currCol] = true;
        for(int i = 0; i < DIRECTION_COUNT; i++) {
            int nextX = currRow + dir[i][0];
            int nextY = currCol + dir[i][1];

            // Limitation
            if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
            if(graph[currRow][currCol] < graph[nextX][nextY]) continue;
            
            dfs(graph, visited, nextX, nextY);
        }
        return;
    }
};


// Function to create graph
std::vector<std::vector<int>> createGraph(int rowCount, int colCount) {
    // Initialize a graph
    std::vector<std::vector<int>> graph(rowCount, std::vector<int>(colCount));
    // Using the for-loop to create the Graph
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            std::cin >>  graph[i][j];
        }
    }
    return graph;
};

// Function to print the Graph
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
    // Get the Resout
    Solution sol;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sol.isResult(graph, i, j, rows, cols);
        }
    }
};


/**
 * 
 * 時間複雜度計算
 * 
 * 1. 主函式中
 *     
 * 
 *  for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sol.isResult(graph, i, j, rows, cols);
        }
    }
    時間複雜度為 O(rows * cols)

    2. isResults

    --> 這個函式會呼叫 dfs
    --> 並且也會執行邊界測試 --> 
        每個迴圈的複雜度是 O(rowCount)或 O(colCount) 總共4次。
        時間複雜度為 O(rowCount + colCount)

    3. dfs 

    for(int i = 0; i < DIRECTION_COUNT; i++) {
        int nextX = currRow + dir[i][0];
        int nextY = currCol + dir[i][1];
        if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
        if(graph[currRow][currCol] < graph[nextX][nextY]) continue;
        dfs(graph, visited, nextX, nextY);
    }

    --> DFS 的時間複雜度：取決於矩陣中每個節點訪問的次數
    --> 每個節點最多被訪問一次，每次訪問檢查四個方向
    --> 時間複雜度 O(rows * cols)



    1.isResult 的時間複雜度
    isResult 的時間複雜度是：
    O(rowCount + colCount) + O(rows * cols)
    這表示邊界檢查和 DFS 的時間複雜度是相加的，而不是嵌套的。
    
    2.主函數的迴圈
    - 主函數的迴圈會對每個單元格呼叫一次 isResult。
    - 因此，總時間複雜度是：
    O(rows * cols) * (O(rowCount + colCount) + O(rows * cols))
    
    3.簡化分析
    - 在最壞情況下，rowCount 和 colCount 都接近 rows 和 cols。
    - 因此，O(rowCount + colCount) 可以簡化為 O(rows + cols)。
    - 最終時間複雜度為：
    O(rows * cols * (rows + cols)*2)

    --> 更簡化:
    O(rows * cols * (rows + cols))

 */
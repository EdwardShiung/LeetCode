/*

LeetCode 200: Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.


Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.


ACM 99: Number of Islands

本題與 ACM 99 題目相同。不同點在於， ACM 的考試，常常需要自行創建一個 2D 陣列，
並且將陣列的元素初始化為 0 或 1。這個題目則是給定一個 2D 陣列，並且要求計算陣列中有多少個島嶼。

题目描述
给定一个由 1（陆地）和 0（水）组成的矩阵，你需要计算岛屿的数量。岛屿由水平方向或垂直方向上相邻的陆地连接而成，并且四周都是水域。你可以假设矩阵外均被水包围。

输入描述
第一行包含两个整数 N, M，表示矩阵的行数和列数。

后续 N 行，每行包含 M 个数字，数字为 1 或者 0。

输出描述
输出一个整数，表示岛屿的数量。如果不存在岛屿，则输出 0。

输入示例
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

输出示例
3

提示信息
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
根据测试案例中所展示，岛屿数量共有 3 个，所以输出 3。

数据范围：

1 <= N, M <= 50


本題透過 BFS 寫法，完成此題！

*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Solution {
  public:
  int countIslands(std::vector<std::vector<char>>& graph, int rows, int cols) {
    // Calculate the island
    int count = 0;
    // Check mark for visited island
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        if(!visited[i][j] && graph[i][j] == '1') {
          count++;
          // Mark the adjacent cell
          bfs(graph, visited, i, j);
        }
      }
    }
    return count;
  };

  private:
    // Coordinates of 4 directions (row, col)
    int dir[4][2] = {
      {-1, 0},  //up
      {1, 0},   //down
      {0, 1},   //left
      {0, -1},  //right  
    };
    // Function to the BFS
    void bfs(std::vector<std::vector<char>>& graph, std::vector<std::vector<bool>>& visited, int currRow, int currCol) {
      // Set a queue
      std::queue<std::pair<int, int>> que;
      // Join the current cell to the queue
      que.push({currRow, currCol});
      // Once join to the queue, cell should be marked
      visited[currRow][currCol] = true;
      // Iterate the cells
      while(!que.empty()) {
        // Get the cell from the queue
        std::pair<int, int> curr = que.front();
        // pop out the cell from the queue
        que.pop();
        // Get the current cell information
        // x coordinator of cell
        int currX = curr.first;
        // y coordinator of cell
        int currY = curr.second;
        // Loop the cells around the current cell
        for(int i = 0; i < 4; i++) {
          int nextX = currX + dir[i][0];
          int nextY = currY + dir[i][1];
          // Set the limitation (out of the bound)
          if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
          if(!visited[nextX][nextY] && graph[nextX][nextY] == '1') {
            que.push({nextX, nextY});
            visited[nextX][nextY] = true;
          }
        }
      }
    };
};


//Read the Graph
std::vector<std::vector<char>> readGraph(int rowCount, int colCount){
  
  // Set the size of graph
  std::vector<std::vector<char>> graph(rowCount, std::vector<char>(colCount));
  // Iterate the Graph
  for(int i = 0; i < rowCount; i++) {
    for(int j = 0; j < colCount; j++){
      std::cin >> graph[i][j];
    }
  }
  return graph;
};

// Print the Graph
void printGraph(const std::vector<std::vector<char>>& graph) {
  for(const std::vector<char> row: graph) {
    for(const char cell: row) {
      std::cout << cell << " ";
    }
    std::cout << std::endl;
  }
};


int main() {
  // Input the rows and cols
  int rows, cols;
  std::cin >> rows >> cols;
  // Read the Graph
  std::vector<std::vector<char>> graph = readGraph(rows, cols);

  // Print the Graph
  printGraph(graph);

  Solution sol;

  // Get the number of island
  int results = sol.countIslands(graph, rows, cols);

  // Print the number of island 
  std::cout << "Number of Islands: "  << results << std::endl;
  return 0;
}

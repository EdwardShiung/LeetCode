/**
 * 101. 孤岛的总面积
题目描述
给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿指的是由水平或垂直方向上相邻的陆地单元格组成的区域，且完全被水域单元格包围。
孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿。



现在你需要计算所有孤岛的总面积，岛屿面积的计算方式为组成岛屿的陆地的总数。

输入描述
第一行包含两个整数 N, M，表示矩阵的行数和列数。之后 N 行，每行包含 M 个数字，数字为 1 或者 0。
输出描述
输出一个整数，表示所有孤岛的总面积，如果不存在孤岛，则输出 0。
输入示例
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
输出示例
1
提示信息

在矩阵中心部分的岛屿，因为没有任何一个单元格接触到矩阵边缘，所以该岛屿属于孤岛，总面积为 1。



数据范围：

1 <= M, N <= 50。


[Thought]:

DFS solution
 *  本題“孤島”，強調：所有单元格都不接触边缘的岛屿！！並且，求“孤島”個數！

    由於，題目強調，所有單元格都不接觸邊緣的島嶼，
    換言之，我是否可以先抓出邊緣四周為 "1" 且連接再一起的島嶼，再將他們變成 “0”。
    最後，再次計算孤島總面積 ("1" 沒有靠邊的島嶼)

    file 02 採取 BFS 方式。這邊我們使用 DFS。
 * 
 */

#include <iostream>

#define DIRECTION_COUNT 4

class Solution {
   public:

   // From left side and right side to search the island ("1")
   void leftToRight(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
      for(int i = 0; i < rowCount; i++) {
         // Left
         if(graph[i][0] == '1') dfs(graph, i, 0);
         // Right
         if(graph[i][colCount - 1] == '1') dfs(graph, i, colCount - 1);
      }
   };

   // From top to bottom side to search the island ("1")
   void topToBottom(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
      for(int j = 0; j < colCount; j++) {
         // Top
         if(graph[0][j] == '1') dfs(graph, 0, j);
         // Bottom
         if(graph[rowCount - 1][j] == '1') dfs(graph, rowCount - 1, j);
      }
   };

   // Calculate the Isolated Island
   int countIsolatedIsland(const std::vector<std::vector<char>>& graph) {
      int count = 0;
      for(const std::vector<char> row: graph) {
         for(const char cell : row) {
            if(cell == '1') count++;
         }
      }
      return count;
   }

   private:
   // Coordinator of 4 Directions
   int dir[DIRECTION_COUNT][2] = {
      {-1, 0}, //up
      {1, 0},  //down
      {0, 1},  //right
      {0, -1}, //left
   };

   void dfs(std::vector<std::vector<char>>& graph, int currRow, int currCol ) {
      graph[currRow][currCol] = '0';
      // Iterative to traverse the graph
      for(int i = 0; i < DIRECTION_COUNT; i++) {
         int nextX = currRow + dir[i][0];
         int nextY = currCol + dir[i][1];

         // Limitation
         if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
         if(graph[nextX][nextY] == '0') continue;

         // Iterative the cell
         dfs(graph, nextX, nextY);
      }
   }
};


// Create a Graph
std::vector<std::vector<char>> createGraph(int rowCount, int colCount) {
   
   // Initialize a graph
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
}


int main() {
   
   int rows, cols;
   std::cin >> rows >> cols;

   // Create a Graph
   std::vector<std::vector<char>> graph = createGraph(rows, cols);

   // Print the Graph
   printGraph(graph);

   // Calculate the isolated island
   Solution sol;
   sol.leftToRight(graph, rows, cols);
   sol.topToBottom(graph, rows, cols);
   int results = sol.countIsolatedIsland(graph);

   std::cout << results << std::endl;

   return 0;
}


/**
 * 
 * 我的 printGraph 這部分，參數、迴圈值，需要加上 const嗎？
 */
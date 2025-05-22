// ==========================
// BFS Algorithm Template
// ==========================

/**
 *  注意：這裡會使用 x,y 來表示座標。有別於傳統數學上的 (x,y) 表示法。
 *  程式語言中， X 軸是水平的, Y 軸是垂直的。 
 *  對於圖論的 BFS 練習，可以先看一下 Preview File_Coordinate System。
 * 
 */

 #include <vector>
 #include <queue>
 using namespace std;
 
// Direction vectors for moving right, down, up, and left
// 1st style: 4 directions (up, down, left, right)
int dir[4][2] = {
    {0, 1},   // Right
    {1, 0},   // Down
    {-1, 0},  // Up
    {0, -1}   // Left
};

// 2nd style: 4 directions (up, down, left, right)
//  int dir[4][2] = {0, 1, 1, 0, -1, 0, 0 ,-1};
 /**
  * Performs Breadth-First Search (BFS) from the starting cell (x, y)
  * on a 2D grid.
  *
  * @param grid   A 2D character grid (e.g., maze or map)
  * @param visited A 2D boolean grid to mark visited cells
  * @param x      Starting row index
  * @param y      Starting column index
  */
 void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
     queue<pair<int, int>> que;       // BFS queue for traversal
     que.push({x, y});                // Add the starting cell
     visited[x][y] = true;            // Mark the start as visited immediately
 
     while (!que.empty()) {
         pair<int, int> cur = que.front(); que.pop();  // Get the current cell
         int curx = cur.first;
         int cury = cur.second;
 
         // Explore four directions from the current cell
         for (int i = 0; i < 4; i++) {
             int nextx = curx + dir[i][0];
             int nexty = cury + dir[i][1];
 
             // Check bounds
             if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
 
             // If not visited, add to queue and mark as visited
             if (!visited[nextx][nexty]) {
                 que.push({nextx, nexty});
                 visited[nextx][nexty] = true;
             }
         }
     }
 }





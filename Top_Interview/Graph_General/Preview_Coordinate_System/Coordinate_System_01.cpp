/**
 *  Coordinate System Introduction
 * 
 * 
 * 
 * 

 給定：
一個 n x m 的地圖 grid，由 '0' 和 '1' 組成

'0' 表示可以走

'1' 表示牆（不能走）

起點是 (0, 0)，終點是 (n-1, m-1)

只能往上下左右走，不能走對角線

📌 任務：
請你用 BFS 算出「從起點走到終點的最短步數」，若無法到達，回傳 -1

範例輸入：

vector<vector<char>> grid = {
    {'0', '0', '1', '0'},
    {'1', '0', '1', '0'},
    {'0', '0', '0', '0'},
    {'0', '1', '1', '0'}
};

輸出：
7
 */


 #include <iostream>
 #include <vector>
 #include <queue>
 #include <utility>
 using namespace std;


// Define the movement directions
// hypothesis: 4 directions (up, down, left, right)
// Current Point is (x, y)
int dir[4][2] = {
    {-1, 0},    // Up
    {1, 0},     // Down
    {0, -1},    // Left
    {0, 1},     // Right
};

// BFS function to find the shortest path
/**
 *  Parameters:
 *  grid: The input grid (2D vector)
 *  visited: A 2D vector to keep track of visited cells
 *  x: Current x-coordinate
 *  y: Current y-coordinate
 *  Returns: The number of steps to reach the destination or -1 if unreachable
 */
int bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
    // Initialize the steps
    int steps = 0;

    // Understand the gird row and column
    // Number of rows
    int row = grid.size();
    // Number of columns
    int col = grid[0].size();

    // Define the queue for BFS
    queue<pair<int, int>> que;
    // Push the starting point into the queue
    que.push({x, y});
    // Mark the starting point as visited
    visited[x][y] = true;

    // BSF loop
    while(!que.empty()) {
        // Get the size of the queue
        int size = que.size();
        // Process all nodes at the current level
        while(size--){
            // Get the current point
            pair<int, int> cur = que.front();
            // pop the current point from the queue
            que.pop();
            // Get the current x and y coordinates
            // x is 
            int x = cur.first;
            int y = cur.second;

            // Check if we have reached the destination
            if(x == row - 1 && y == col - 1) return steps;

            // Iterate through all possible directions
            for(int i = 0; i < 4; i++) {
                // Calculate the new coordinates
                int nextX = x + dir[i][0];
                int nextY = y + dir[i][1];

                // Check if the new coordinates are within bounds and not visited
                if(nextX < 0 || nextX >= row || nextY < 0 || nextY >= col) continue; // Out of bounds
                if(grid[nextX][nextY] == '1') continue; // Wall
                if(visited[nextX][nextY] == true) continue; // Already visited

                // Mark the new coordinates as visited
                visited[nextX][nextY] = true;
                // Push the new coordinates into the queue
                que.push({nextX, nextY});
            }

        }
        steps++;
    }
    return -1; // If we reach here, it means we couldn't reach the destination
}


int main() {
    // Define the grid
    vector<vector<char>> grid = {    
        {'0', '0', '1', '0'},
        {'1', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'0', '1', '1', '0'}
    };
    // vector<vector<char>> grid = {    
    //     {'0'}
    // };

    // Initialize the visited array
    // grid size
    // Number of rows
    int row = grid.size();
    // Number of columns
    int col = grid[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    // Start BFS from (0, 0)
    int startX = 0;
    int startY = 0;
    int result = bfs(grid, visited, startX, startY);
    // Print the result
    if(result == -1) {
        cout << "No path found" << endl;
    } else {
        cout << "Shortest path length: " << result << endl;
    }
    return 0;
}
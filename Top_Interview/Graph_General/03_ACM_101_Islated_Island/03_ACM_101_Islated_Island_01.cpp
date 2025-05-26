#include <iostream>
#include <vector>
#include <queue>

#define DIRECTION_COUNT 4

class Solution {
    
    public:
    bool findIslatedIsland(std::vector<std::vector<char>>& graph, int rowCount, int colCount) {
        bool hasIslated = false;
        std::vector<std::vector<bool>> visited(rowCount, std::vector<bool>(colCount, false));
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                if(!visited[i][j] && graph[i][j] == '1') {
                    bfs(graph, visited, i, j, hasIslated);
                }
            }
        }
        return hasIslated;
    };

    private:
    // coordinator of 4 directions
    int dir[DIRECTION_COUNT][2] = {
        {-1, 0},    //up
        {1, 0},     //down
        {0, -1},    //left
        {0, 1},     //right
    };
    
    void bfs(std::vector<std::vector<char>>& graph, std::vector<std::vector<bool>>& visited, int currRow, int currCol, bool& hasIslated) {
        // Set a queue
        std::queue<std::pair<int, int>> que;
        que.push({currRow, currCol});
        // Record the visited
        visited[currRow][currCol] = true;

        while(!que.empty()) {
            // Get the current cell X and Y
            std::pair<int, int> curr = que.front();
            que.pop();

            // Get the current
            int currX = curr.first;
            int currY = curr.second;

            for(int i = 0; i < DIRECTION_COUNT; i++) {
                int nextX = currX + dir[i][0];
                int nextY = currY + dir[i][1];
                if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
                if(!visited[nextX][nextY] && graph[nextX][nextY] == '0') {
                    hasIslated = true;
                }
            }
        }
    };
};

// Create a Graph
std::vector<std::vector<char>> createGraph(int rowCount, int colCount) {
    std::vector<std::vector<char>> graph(rowCount, std::vector<char>(colCount));
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
};

// Print a Graph
void printGraph(std::vector<std::vector<char>>& graph) {
    for(const std::vector<char> row: graph) {
        for(const char cell: row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    // create a graph
    std::vector<std::vector<char>> graph = createGraph(rows, cols);

    //print a graph
    printGraph(graph);

    // Verified if islated island or not
    Solution sol;
    bool hasIalatedIsland = sol.findIslatedIsland(graph, rows, cols);

    // Print the result
    std::cout << hasIalatedIsland << std::endl;

}
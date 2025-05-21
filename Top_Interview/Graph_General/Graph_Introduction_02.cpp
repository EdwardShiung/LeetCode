#include <iostream>
#include <vector>
/**
 * 1. DFS Pattern
 */

 // ==========================
// Depth-First Search (DFS) Template - "Three Steps"
// ==========================

// Global variables to store all valid paths
vector<vector<int>> result;  // Final results (all paths)
vector<int> path;            // Current path (Single path)

// DFS function definition
void dfs(Graph graph, int currentNode) {
    // 1. Termination condition
    if (/* termination condition */) {
        // Save the current path to result
        result.push_back(path);
        return;
    }

    // 2. Iterate through all choices (adjacent nodes)
    for (int nextNode : graph.adjList[currentNode]) {
        // 3. Make a choice (process the node)
        path.push_back(nextNode);  // or mark as visited if needed

        // 4. Recursive call
        dfs(graph, nextNode);

        // 5. Backtrack (undo the choice)
        path.pop_back();  // or unmark visited
    }
}

/**
 * Some termination conditions will be handled after the loop
 */
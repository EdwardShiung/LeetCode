#include <iostream>

/** Graph 重要概念
 * 1. Type of Graph
 *  - Directed Graph (有向圖)
 *  - Undirected Graph (無向圖)
 *  - Weighted Graph (加權圖)
 * 
 * 2. Graph Representation (LeetCode 練習時，通常已經封裝好給你使用。要注意自己生成結構)
 
 *  - Adjacency Matrix (鄰接矩陣)
 *   - 定義方式 (儲存方式)：使用 陣列 來表示圖的結構
 *   - 邊的數量是 O(V^2)
 *   - V 是頂點的數量
 *   - 適用情況：點少、邊多的情況下
 *   - 優點：容易實現，並且可以快速查詢邊的存在性
 *   - 缺點：容易浪費空間
 * 
 *  - Adjacency List (鄰接表)
 *   - 定義方式 (儲存方式)：使用 陣列 + 鏈表 來表示圖的結構
 *   - 邊的數量是 O(E)
 *   - E 是邊的數量
 *   - 存儲增量，在於邊的數量（邊越多，內存空間才會增加越多）
 *   - 適用情況：邊少、點多的情況下
 *   - 優點：節省空間
 *   - 缺點：
 *     - 邊很多的情況，不適用。因為需要很多內存空間去儲存邊
 *     - 實踐較複雜
 * 
 * 
 *  - Edge List (邊列表)
 * 
 * 3. Graph Traversal
 *  - Depth-First Search (DFS) (深度優先搜尋)
 *  - Breadth-First Search (BFS) (廣度優先搜尋)
 * 
 * 4. Degree, Out-degree, In-degree
 *  - Degree (度數)
 *  - Out-degree (出度)
 *  - In-degree (入度) 
 *
 * 5. Connectivity
 *  - Connected Graph (連通圖)
 *  - Strongly Connected Graph (強連通圖)
 *   - 有向圖裡的連通性 （任何一個節點，可以到達所有節點）
 *  - Connected Component (連通分量)
 *   - 無向圖裡的連通性 （任何一個節點，可以到達所有節點）
 *    - 無向圖裡的，極大聯通子圖
 *    - 一個圖，可能有數個極大聯通子圖
 *  - Strongly Connected Component (強連通分量)
 *  
 */
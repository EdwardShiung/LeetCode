初始状态: path = [1]
🟢 dfs(graph, start=1, end=5)
│   参数: start=1, end=5, path=[1]
│   条件: 1 != 5, 继续执行
│   邻居: graph[1] = [3, 2] → 开始for循环遍历
│
├─ 🔹 选择节点 3 (for循环第1次迭代, i=3)
│  │ 输出: "進入到 path 3 "
│  │ path = [1, 3] ← push_back(3)
│  │ 
│  │ 🟢 dfs(graph, start=3, end=5)
│  │    参数: start=3, end=5, path=[1, 3]
│  │    条件: 3 != 5, 继续执行
│  │    邻居: graph[3] = [5] → 开始for循环遍历
│  │    │
│  │    ├─ 🔹 选择节点 5 (for循环第1次迭代, i=5)
│  │    │  │ 输出: "進入到 path 5 "
│  │    │  │ path = [1, 3, 5] ← push_back(5)
│  │    │  │
│  │    │  │ 🟢 dfs(graph, start=5, end=5)
│  │    │  │    参数: start=5, end=5, path=[1, 3, 5]
│  │    │  │    条件: 5 == 5 ✅ 达到目标！
│  │    │  │    动作: results.push_back([1, 3, 5])
│  │    │  │    🔙 return (结束递归) → 直接返回，不执行for循环
│  │    │  │
│  │    │  │ 输出: "回溯移除 path 5 "
│  │    │  └─ 🔄 回溯: path.pop_back() → path = [1, 3]
│  │    │
│  │    └─ 📝 for循环遍历完毕原因: 
│  │         - graph[3] = [5] 只有1个元素
│  │         - i=5 已处理完毕，for循环结束
│  │         - 没有更多邻居节点可遍历
│  │    🔙 return (结束递归)
│  │
│  │ 输出: "回溯移除 path 3 "
│  └─ 🔄 回溯: path.pop_back() → path = [1]
│
├─ 🔹 选择节点 2 (for循环第2次迭代, i=2)
│  │ 输出: "進入到 path 2 "
│  │ path = [1, 2] ← push_back(2)
│  │
│  │ 🟢 dfs(graph, start=2, end=5)
│  │    参数: start=2, end=5, path=[1, 2]
│  │    条件: 2 != 5, 继续执行
│  │    邻居: graph[2] = [4] → 开始for循环遍历
│  │    │
│  │    ├─ 🔹 选择节点 4 (for循环第1次迭代, i=4)
│  │    │  │ 输出: "進入到 path 4 "
│  │    │  │ path = [1, 2, 4] ← push_back(4)
│  │    │  │
│  │    │  │ 🟢 dfs(graph, start=4, end=5)
│  │    │  │    参数: start=4, end=5, path=[1, 2, 4]
│  │    │  │    条件: 4 != 5, 继续执行
│  │    │  │    邻居: graph[4] = [5] → 开始for循环遍历
│  │    │  │    │
│  │    │  │    ├─ 🔹 选择节点 5 (for循环第1次迭代, i=5)
│  │    │  │    │  │ 输出: "進入到 path 5 "
│  │    │  │    │  │ path = [1, 2, 4, 5] ← push_back(5)
│  │    │  │    │  │
│  │    │  │    │  │ 🟢 dfs(graph, start=5, end=5)
│  │    │  │    │  │    参数: start=5, end=5, path=[1, 2, 4, 5]
│  │    │  │    │  │    条件: 5 == 5 ✅ 达到目标！
│  │    │  │    │  │    动作: results.push_back([1, 2, 4, 5])
│  │    │  │    │  │    🔙 return (结束递归) → 直接返回，不执行for循环
│  │    │  │    │  │
│  │    │  │    │  │ 输出: "回溯移除 path 5 "
│  │    │  │    │  └─ 🔄 回溯: path.pop_back() → path = [1, 2, 4]
│  │    │  │    │
│  │    │  │    └─ 📝 for循环遍历完毕原因:
│  │    │  │         - graph[4] = [5] 只有1个元素
│  │    │  │         - i=5 已处理完毕，for循环结束
│  │    │  │         - 没有更多邻居节点可遍历
│  │    │  │    🔙 return (结束递归)
│  │    │  │
│  │    │  │ 输出: "回溯移除 path 4 "
│  │    │  └─ 🔄 回溯: path.pop_back() → path = [1, 2]
│  │    │
│  │    └─ 📝 for循环遍历完毕原因:
│  │         - graph[2] = [4] 只有1个元素
│  │         - i=4 已处理完毕，for循环结束
│  │         - 没有更多邻居节点可遍历
│  │    🔙 return (结束递归)
│  │
│  │ 输出: "回溯移除 path 2 "
│  └─ 🔄 回溯: path.pop_back() → path = [1]
│
└─ 📝 for循环遍历完毕原因:
     - graph[1] = [3, 2] 有2个元素
     - i=3 已处理完毕 (第1次迭代)
     - i=2 已处理完毕 (第2次迭代)  
     - 所有邻居节点都已遍历完毕，for循环结束
🔙 算法结束


# C++函数的返回机制

1. 显式return vs 隐式return
void dfs(const std::vector<std::list<int>>& graph, int start, int end)
{
    if(start == end)
    {
        results.push_back(path);
        return;  // ← 这是显式return
    }
    
    for(int i : graph[start])
    {
        path.push_back(i);
        dfs(graph, i, end);
        path.pop_back();
    }
    // ← 这里有隐式return，函数自然结束
}

2. for循环结束后的流程
当for循环遍历完所有邻居节点后：

for(int i : graph[start])  // 假设 graph[3] = [5]
{
    // i = 5, 第1次迭代
    path.push_back(5);     // path = [1, 3, 5]
    dfs(graph, 5, 5);      // 递归调用
    path.pop_back();       // path = [1, 3]
    // 第1次迭代结束
    
    // 没有更多元素了，for循环结束
}

// for循环结束后，函数继续往下执行
// 但是没有更多代码了，所以函数自然结束
// 这相当于一个隐式的 return;
#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>

void dfs(int src, std::vector<std::vector<int>> &graph, std::unordered_set<int> &visited, std::stack<int> &sorting)
{
    visited.insert(src);
    for (int i : graph[src])
    {
        if (visited.count(i) == 0)
        {
            dfs(i, graph, visited, sorting);
        }
    }
    sorting.push(src);
}

std::vector<int> topologicalSort(std::vector<std::vector<int>> &graph)
{
    std::unordered_set<int> visited;
    std::stack<int> sorting;

    for (int i = 1; i <= 6; i++)
    {
        if (visited.count(i) == 0)
            dfs(i, graph, visited, sorting);
    }

    std::vector<int> result(sorting.size());

    for (int i = 0; i < result.size(); i++)
    {
        result[i] = sorting.top();
        sorting.pop();
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> adjList;
    std::vector<std::pair<int, int>> edges = {{1, 2}, {2, 3}, {5, 3}, {4, 1}, {4, 5}, {6, 5}, {6, 4}};

    adjList.resize(7);

    for (auto edge : edges)
    {
        adjList[edge.first].push_back(edge.second);
    }

    std::vector<int> result = topologicalSort(adjList);

    for (int i : result)
    {
        std::cout << i << " ";
    }

    return 0;
}
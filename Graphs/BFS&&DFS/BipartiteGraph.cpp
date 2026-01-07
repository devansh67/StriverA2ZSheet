#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/is-graph-bipartite/description/


// DFS Solution
class Solution
{
public:
    bool dfs(int node, vector<int> &color, vector<vector<int>> &graph, int &n)
    {
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                if (!dfs(it, color, graph, n))
                    return false;
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                if (!dfs(i, color, graph, n))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

// BFS Solution
class Solution2
{
public:
    bool bfs(vector<int> &color, vector<vector<int>> &graph, queue<int> &q)
    {
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            for (int adjacentNode : graph[it])
            {
                if (color[adjacentNode] == -1)
                {
                    color[adjacentNode] = 1 - color[it];
                    q.push(adjacentNode);
                }
                else if (color[adjacentNode] == color[it])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (color[i] != -1)
            {
                continue;
            }
            color[i] = 0;
            q.push(i);

            if (!bfs(color, graph, q))
            {
                return false;
            }
        }

        return true;
    }
};
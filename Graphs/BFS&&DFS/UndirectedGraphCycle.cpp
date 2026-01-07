#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// DFS Approach
class Solution
{
public:
    bool dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
                if (dfs(adjacentNode, node, visited, adj))
                {
                    return true;
                }
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, visited, adj))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

// BFS Approach
class Solution2
{
public:
    bool detect(int src, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[src] = 1;
        queue<pair<int, int>> q;

        q.push({src, -1});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int parent = it.second;

            for (auto adjacentNode : adj[node])
            {
                if (!visited[adjacentNode])
                {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detect(i, adj, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
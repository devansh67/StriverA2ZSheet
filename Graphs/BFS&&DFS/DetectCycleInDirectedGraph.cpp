#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
                if (dfs(adjacentNode, adj, visited, pathVisited))
                {
                    return true;
                }
            }
            else if (pathVisited[adjacentNode])
            {
                return true;
            }
        }

        pathVisited[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V + 1);
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, pathVisited))
                    return true;
            }
        }

        return false;
    }
};
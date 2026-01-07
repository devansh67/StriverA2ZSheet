#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution
{
public:
    vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
    {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        vector<int> distance(n, INT_MAX);
        queue<int> q;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        distance[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            for (auto adjacentNode : adj[it])
            {
                if (distance[it] + 1 < distance[adjacentNode])
                {
                    distance[adjacentNode] = distance[it] + 1;
                    q.push(adjacentNode);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }

        return distance;
    }
};
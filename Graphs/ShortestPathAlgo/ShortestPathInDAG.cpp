#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &visited, stack<int> &st, int &n)
    {
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it.first])
            {
                dfs(it.first, adj, visited, st, n);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int n, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> visited(n, 0);
        vector<int> distance(n, INT_MAX);
        stack<int> st;

        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st, n);
            }
        }

        while (st.top() != 0)
        {
            st.pop();
        }

        distance[0] = 0;
        while (!st.empty())
        {
            auto it = st.top();
            st.pop();
            if (distance[it] != INT_MAX)
            {
                for (auto adjacentNode : adj[it])
                {
                    distance[adjacentNode.first] =
                        min(distance[it] + adjacentNode.second, distance[adjacentNode.first]);
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

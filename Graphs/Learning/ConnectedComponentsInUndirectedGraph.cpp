#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

class Solution
{
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &visited, vector<int> &temp, int &n)
    {
        visited[i] = 1;
        temp.push_back(i);

        for (auto it : adj[i])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, temp, n);
            }
        }
    }

    vector<vector<int>> getComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n + 1, 0);

        vector<vector<int>> answer;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int> temp;
                dfs(i, adj, visited, temp, n);
                answer.push_back(temp);
            }
        }

        return answer;
    }
};
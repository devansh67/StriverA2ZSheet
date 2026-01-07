#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution
{
public:
    void solve(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &answer)
    {
        visited[node] = 1;
        answer.push_back(node);

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                solve(it, adj, visited, answer);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> visited(n + 1, 0);
        vector<int> answer;

        solve(0, adj, visited, answer);

        return answer;
    }
};
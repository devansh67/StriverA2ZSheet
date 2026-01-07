#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/find-eventual-safe-states/description/

// DFS Solution
class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, vector<int> &checker)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        checker[node] = 0;

        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
                if (dfs(adjacentNode, adj, visited, pathVisited, checker))
                {
                    checker[node] = 0;
                    return true;
                }
            }
            else if (pathVisited[adjacentNode])
            {
                checker[node] = 0;
                return true;
            }
        }

        checker[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);
        vector<int> checker(n, 0);
        vector<int> answer;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, pathVisited, checker);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (checker[i] == 1)
            {
                answer.push_back(i);
            }
        }

        return answer;
    }
};
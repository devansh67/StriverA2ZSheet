#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> visited(n, 0);
        queue<int> q;
        vector<int> answer;
        visited[0] = 1;
        q.push(0);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            answer.push_back(curr);

            for (auto it : adj[curr])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }

        return answer;
    }
};
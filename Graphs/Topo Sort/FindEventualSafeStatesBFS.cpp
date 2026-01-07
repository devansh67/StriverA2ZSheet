#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> answer;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                answer.push_back(i);
                q.push(i);
            }
        }

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            for (auto adjacentNode : adj[it])
            {
                indegree[adjacentNode]--;
                if (indegree[adjacentNode] == 0)
                {
                    answer.push_back(adjacentNode);
                    q.push(adjacentNode);
                }
            }
        }

        sort(answer.begin(), answer.end());
        return answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/course-schedule-ii/description/

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> indegree(n, 0);
        vector<int> answer;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

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
        if (answer.size() != n)
            answer.clear();

        return answer;
    }
};
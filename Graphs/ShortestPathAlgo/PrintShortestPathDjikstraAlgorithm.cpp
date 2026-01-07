#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> distance(n + 1, INT_MAX);
        vector<int> parentArr(n + 1);
        for(int i = 1; i<=n; i++)
        {
            parentArr[i] = i;
        }
        vector<int> answer;

        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        pq.push({0, 1});
        distance[1] = 0;

        while (!pq.empty())
        {
            auto presentNode = pq.top().second;
            auto presentCost = pq.top().first;
            pq.pop();

            if (presentCost != distance[presentNode])
                continue;

            for (auto it : adj[presentNode])
            {
                int newNode = it.first;
                int edgeWt = it.second;
                int newCost = presentCost + edgeWt;
                if (newCost < distance[newNode])
                {
                    distance[newNode] = newCost;
                    parentArr[newNode] = presentNode;
                    pq.push({newCost, newNode});
                }
            }
        }

        if (distance[n] == INT_MAX)
        {
            return {-1};
        }
        int node = n;

        while (parentArr[node] != node)
        {
            answer.push_back(node);
            node = parentArr[node];
        }
        answer.push_back(1);
        reverse(answer.begin(), answer.end());
        answer.insert(answer.begin(), distance[n]);

        return answer;
    }
};
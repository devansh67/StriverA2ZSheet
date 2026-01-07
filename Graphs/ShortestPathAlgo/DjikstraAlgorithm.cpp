#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        distance[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto nodeDistance = pq.top().first;
            auto nodeValue = pq.top().second;
            pq.pop();

            if (distance[nodeValue] != nodeDistance)
                continue;

            for (auto adjacentNode : adj[nodeValue])
            {
                int newDistance = adjacentNode.second + nodeDistance;
                if (newDistance < distance[adjacentNode.first])
                {
                    distance[adjacentNode.first] = newDistance;
                    pq.push({newDistance, adjacentNode.first});
                }
            }
        }

        return distance;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/topological-sort/1

// BFS Solution (Kahn's Algorithm)

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> answer;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            answer.push_back(it);

            for (auto adjacentNode : adj[it])
            {
                indegree[adjacentNode]--;
                if (indegree[adjacentNode] == 0)
                {
                    q.push(adjacentNode);
                }
            }
        }

        return answer;
    }
};

// DFS Solution
class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st, int &n)
    {
        visited[node] = 1;

        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
                dfs(adjacentNode, adj, visited, st, n);
            }
        }
        st.push(node);
    }

    vector<int> topoSort(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        stack<int> st;
        vector<int> answer;
        vector<int> visited(n, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st, n);
            }
        }

        while (!st.empty())
        {
            auto it = st.top();
            answer.push_back(it);
            st.pop();
        }

        return answer;
    }
};
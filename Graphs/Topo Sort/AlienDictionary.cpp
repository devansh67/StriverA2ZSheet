#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution
{
public:
    string findOrder(vector<string> &words)
    {
        int n = words.size();
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        string answer = "";

        for (int i = 0; i < n; i++)
        {
            for (auto it : words[i])
            {
                indegree[it] = 0;
            }
        }

        for (int i = 1; i < n; i++)
        {
            string s1 = words[i - 1];
            string s2 = words[i];

            int j = 0;
            int k = 0;
            while (j < s1.length() && k < s2.length())
            {
                if (s1[j] != s2[k])
                {
                    adj[s1[j]].push_back(s2[k]);
                    indegree[s2[k]]++;
                    break;
                }
                j++;
                k++;
            }

            if(j < s1.length() && k == s2.length())
            {
                return "";
            }
        }

        queue<char> q;
        for (auto it : indegree)
        {
            if (it.second == 0)
            {
                q.push(it.first);
            }
        }

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            answer.push_back(it);

            vector<char> adjacentNodes = adj[it];
            for (auto adjacentNode : adjacentNodes)
            {
                indegree[adjacentNode]--;
                if (indegree[adjacentNode] == 0)
                {
                    q.push(adjacentNode);
                }
            }
        }

        if (answer.length() != indegree.size())
        {
            return "";
        }

        return answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

class Solution
{
public:
    vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
    {
        int m = a.size();
        int n = b.size();

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<int> answer;

        sort(a.begin(), a.end(), greater());
        sort(b.begin(), b.end(), greater());

        for (int i = 0; i < min(m, k); i++)
        {
            int sum = a[i] + b[0];
            pq.push({sum, {i, 0}});
        }

        while (k-- > 0 && !pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            answer.push_back(it.first);

            int i = it.second.first;
            int j = it.second.second;

            if (j + 1 < n)
            {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
            }
        }

        sort(answer.begin(), answer.end(), greater());

        return answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/rank-transform-of-an-array/description/

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int rank = 1;
        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++)
        {
            pq.push({arr[i], i});
        }

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            answer[it.second] = rank;
            if (it.first != pq.top().first)
            {
                rank++;
            }
        }

        return answer;
    }
};
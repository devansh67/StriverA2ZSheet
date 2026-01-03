#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        priority_queue<pair<int, vector<int>>> pq;

        vector<vector<int>> answer;

        for (auto it : points)
        {
            int value = (it[0] * it[0]) + (it[1] * it[1]);
            pq.push({value, it});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            auto it = pq.top().second;
            answer.push_back(it);
            pq.pop();
        }

        return answer;
    }
};
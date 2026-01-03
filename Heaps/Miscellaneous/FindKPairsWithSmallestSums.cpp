#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<int>> answer;

        for (int i = 0; i < min(k, m); i++)
        {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (k-- > 0 && !pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            answer.push_back({nums1[i], nums2[j]});

            if (j + 1 < n)
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return answer;
    }
};
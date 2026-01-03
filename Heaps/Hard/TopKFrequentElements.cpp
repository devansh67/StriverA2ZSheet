#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> answer;

        for (auto it : nums)
        {
            mp[it]++;
        }

        for (auto it : mp)
        {
            pq.push({it.second, it.first});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};
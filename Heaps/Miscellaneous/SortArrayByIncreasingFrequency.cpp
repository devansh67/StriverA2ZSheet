#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

struct comparator
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first > b.first;
        }
    }
};

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

        vector<int> answer;

        for (auto it : nums)
        {
            mp[it]++;
        }

        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        while (!pq.empty())
        {
            auto temp = pq.top();
            int i = 0;
            while (i < temp.first)
            {
                answer.push_back(temp.second);
                i++;
            }
            pq.pop();
        }

        return answer;
    }
};
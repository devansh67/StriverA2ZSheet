#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-k-closest-elements/description/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;

        vector<int> answer;

        for (auto it : arr)
        {
            pq.push({abs(it - x), it});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            answer.push_back(it.second);
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};
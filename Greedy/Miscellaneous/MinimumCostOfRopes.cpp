#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int total_cost = 0;

        for (auto it : arr)
        {
            pq.push(it);
        }

        while (pq.size() > 1)
        {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            int current_cost = first + second;
            total_cost += current_cost;
            pq.push(current_cost);
        }

        return total_cost;
    }
};
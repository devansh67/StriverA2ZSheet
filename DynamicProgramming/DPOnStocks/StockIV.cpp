#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution
{
public:
    int solve(int i, int buy, int capacity, vector<int> &prices, vector<vector<vector<int>>> &v, int n)
    {
        if (i == n || capacity == 0)
            return 0;

        if (v[i][buy][capacity] != -1)
            return v[i][buy][capacity];

        int profit = 0;
        if (buy)
        {
            int take = -prices[i] + solve(i + 1, 0, capacity, prices, v, n);
            int notTake = solve(i + 1, 1, capacity, prices, v, n);
            profit = max(take, notTake);
        }
        else
        {
            int take = prices[i] + solve(i + 1, 1, capacity - 1, prices, v, n);
            int notTake = solve(i + 1, 0, capacity, prices, v, n);
            profit = max(take, notTake);
        }

        return v[i][buy][capacity] = profit;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> v(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices, v, n);
    }
};
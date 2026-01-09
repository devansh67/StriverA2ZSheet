#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution
{
public:
    int solve(int i, int buy, vector<int> &prices, vector<vector<int>> &v, int n)
    {
        if (i >= n)
            return 0;

        int profit = 0;

        if (v[i][buy] != -1)
            return v[i][buy];

        if (buy)
        {
            int take = -prices[i] + solve(i + 1, false, prices, v, n);
            int notTake = solve(i + 1, true, prices, v, n);
            profit = max(take, notTake);
        }
        else
        {
            int take = prices[i] + solve(i + 2, true, prices, v, n);
            int notTake = solve(i + 1, false, prices, v, n);
            profit = max(take, notTake);
        }

        return v[i][buy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> v(n, vector<int>(2, -1));

        return solve(0, 1, prices, v, n);
    }
};
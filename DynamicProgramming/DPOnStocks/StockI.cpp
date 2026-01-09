#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://accounts.google.com/b/0/AddMailService

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int minimumPrice = prices[0];
        int profit = 0;

        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - minimumPrice;
            profit = max(cost, profit);
            minimumPrice = min(prices[i], minimumPrice);
        }

        return profit;
    }
};
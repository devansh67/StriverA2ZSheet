#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int minimumPrice = prices[0];
        int answer = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            answer = max((prices[i] - minimumPrice), answer);
            minimumPrice = min(prices[i], minimumPrice);
        }
        return (answer == INT_MIN || answer < 0) ? 0 : answer;
    }
};
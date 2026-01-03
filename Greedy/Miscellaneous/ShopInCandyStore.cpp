#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> minMaxCandy(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<int> answer;
        int minimumCost = 0;
        int maximumCost = 0;

        sort(prices.begin(), prices.end());

        int i = 0;
        int j = n - 1;

        // Calculating minimum

        while (i <= j)
        {
            minimumCost += prices[i];
            j -= k;
            i++;
        }

        reverse(prices.begin(), prices.end());
        i = 0;
        j = n - 1;

        // Calculating maximum

        while (i <= j)
        {
            maximumCost += prices[i];
            j -= k;
            i++;
        }

        answer.push_back(minimumCost);
        answer.push_back(maximumCost);

        return answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/coin-change/description/

class Solution
{
public:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &v)
    {
        if (i == 0)
        {
            if (amount % coins[i] == 0)
                return amount / coins[i];
            else
                return 1e8;
        }

        if (amount == 0)
            return 0;

        if (v[i][amount] != -1)
            return v[i][amount];

        int pick = INT_MAX;
        if (coins[i] <= amount)
            pick = 1 + solve(i, amount - coins[i], coins, v);

        int notPick = solve(i - 1, amount, coins, v);

        return v[i][amount] = min(pick, notPick);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> v(n, vector<int>(amount + 1, -1));

        int answer = solve(n - 1, amount, coins, v);

        if (answer >= 1e8)
            return -1;

        return answer;
    }
};
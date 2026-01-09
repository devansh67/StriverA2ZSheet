#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/coin-change-ii/description/

class Solution
{
public:
    int solve(int i, int j, vector<int> &coins, vector<vector<int>> &v)
    {
        if (j == 0)
            return 1;

        if (i == 0)
            return (j % coins[i]) == 0 ? 1 : 0;

        if (v[i][j] != -1)
            return v[i][j];

        int pick = 0;
        if (coins[i] <= j)
            pick = solve(i, j - coins[i], coins, v);

        int notPick = solve(i - 1, j, coins, v);

        return v[i][j] = (pick + notPick);
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> v(n, vector<int>(amount + 1, -1));

        return solve(n - 1, amount, coins, v);
    }
};
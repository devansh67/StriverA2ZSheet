#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
public:
    int solve(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &v)
    {
        if (W == 0)
            return 0;

        if (i == 0)
        {
            if (wt[i] <= W)
                return val[i];
            else
                return 0;
        }

        if (v[i][W] != -1)
            return v[i][W];

        int pick = INT_MIN;
        if (wt[i] <= W)
            pick = val[i] + solve(i - 1, W - wt[i], wt, val, v);

        int notPick = solve(i - 1, W, wt, val, v);

        return v[i][W] = max(pick, notPick);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        vector<vector<int>> v(n, vector<int>(W + 1, -1));

        return solve(n - 1, W, wt, val, v);
    }
};
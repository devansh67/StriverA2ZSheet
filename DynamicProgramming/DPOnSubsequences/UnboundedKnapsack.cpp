#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

class Solution
{
public:
    int solve(int i, int j, vector<int> &wt, vector<int> &val, vector<vector<int>> &v)
    {
        if (i == 0)
            return (j / wt[i]) * val[i];

        if (v[i][j] != -1)
            return v[i][j];

        int pick = 0;
        if (wt[i] <= j)
        {
            pick = val[i] + solve(i, j - wt[i], wt, val, v);
        }

        int notPick = solve(i - 1, j, wt, val, v);

        return v[i][j] = max(pick, notPick);
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = wt.size();
        vector<vector<int>> v(n, vector<int>(capacity + 1, -1));

        return solve(n - 1, capacity, wt, val, v);
    }
};
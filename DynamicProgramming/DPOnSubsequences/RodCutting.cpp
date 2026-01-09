#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution
{
public:
    int solve(int i, int j, vector<int> &price, vector<vector<int>> &v)
    {
        if (j == 0)
            return 0;

        if (i == 0)
            return j * price[i];

        if (v[i][j] != -1)
            return v[i][j];

        int pick = -1e9;
        int rodLength = i + 1;
        if (rodLength <= j)
            pick = price[i] + solve(i, j - rodLength, price, v);
        int notPick = solve(i - 1, j, price, v);

        return v[i][j] = max(pick, notPick);
    }

    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> v(n, vector<int>(n + 1, -1));

        return solve(n - 1, n, price, v);
    }
};
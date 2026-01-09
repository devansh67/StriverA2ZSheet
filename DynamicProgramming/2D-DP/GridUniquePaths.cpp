#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/unique-paths/

class Solution
{
public:
    int solve(int i, int j, int &m, int &n, vector<vector<int>> &v)
    {
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        if (v[i][j] != -1)
            return v[i][j];

        int up = solve(i - 1, j, m, n, v);
        int left = solve(i, j - 1, m, n, v);

        return v[i][j] = up + left;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> v(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, m, n, v);
    }
};
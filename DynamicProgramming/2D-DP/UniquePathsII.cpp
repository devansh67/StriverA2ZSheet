#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/unique-paths-ii/description/

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &v)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }

        if (i < 0 || j < 0 || grid[i][j] == 1)
        {
            return 0;
        }

        if (v[i][j] != -1)
        {
            return v[i][j];
        }

        int up = solve(i - 1, j, grid, v);
        int left = solve(i, j - 1, grid, v);

        return v[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> v(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, grid, v);
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/minimum-path-sum/description/

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> v(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    v[i][j] = grid[i][j];
                }
                else
                {
                    int first = INT_MAX;
                    int second = INT_MAX;

                    if (i > 0)
                        first = grid[i][j] + v[i - 1][j];
                    if (j > 0)
                        second = grid[i][j] + v[i][j - 1];

                    v[i][j] = min(first, second);
                }
            }
        }

        return v[m - 1][n - 1];
    }
};

// Memoization
class Solution2
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &v)
    {
        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return 1e9;

        if (v[i][j] != -1)
        {
            return v[i][j];
        }

        int up = grid[i][j] + solve(i - 1, j, grid, v);
        int left = grid[i][j] + solve(i, j - 1, grid, v);

        return v[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> v(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, grid, v);
    }
};
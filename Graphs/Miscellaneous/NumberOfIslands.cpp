#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/number-of-islands/description/

class Solution
{
public:
    vector<int> nrow = {-1, 1, 0, 0};
    vector<int> ncol = {0, 0, -1, 1};
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited, int m, int n)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1' || visited[row][col] == 1)
        {
            return;
        }
        visited[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            dfs(row + nrow[i], col + ncol[i], grid, visited, m, n);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int answer = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid, visited, m, n);
                    answer++;
                }
            }
        }

        return answer;
    }
};
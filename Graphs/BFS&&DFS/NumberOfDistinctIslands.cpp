#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

class Solution
{
    vector<int> newRow = {-1, 1, 0, 0};
    vector<int> newCol = {0, 0, -1, 1};

public:
    void dfs(int row, int col, int &baseRow, int &baseCol, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &temp, int &m, int &n)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || grid[row][col] != 1)
        {
            return;
        }

        visited[row][col] = 1;
        temp.push_back({row - baseRow, col - baseCol});

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + newRow[i];
            int ncol = col + newCol[i];
            dfs(nrow, ncol, baseRow, baseCol, grid, visited, temp, m, n);
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        set<vector<pair<int, int>>> s;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    int baseRow = i;
                    int baseCol = j;
                    vector<pair<int, int>> temp;
                    dfs(i, j, baseRow, baseCol, grid, visited, temp, m, n);

                    s.insert(temp);
                }
            }
        }

        return s.size();
    }
};
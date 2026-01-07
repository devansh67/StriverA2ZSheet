#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        vector<int> newRow = {-1, 1, 0, 0};
        vector<int> newCol = {0, 0, -1, 1};
        int answer = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + newRow[i];
                int ncol = col + newCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    answer++;
                }
            }
        }

        return answer;
    }
};
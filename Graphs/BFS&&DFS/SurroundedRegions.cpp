#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/surrounded-regions/description/

class Solution
{
public:
    vector<int> newRow = {0, 0, -1, 1};
    vector<int> newCol = {1, -1, 0, 0};

    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &visited, int &m, int &n)
    {
        if (visited[row][col])
        {
            return;
        }
        visited[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + newRow[i];
            int ncol = col + newCol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, board, visited, m, n);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(i, 0, board, visited, m, n);
            }

            if (board[i][n - 1] == 'O')
            {
                dfs(i, n - 1, board, visited, m, n);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(0, i, board, visited, m, n);
            }

            if (board[m - 1][i] == 'O')
            {
                dfs(m - 1, i, board, visited, m, n);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    if (!visited[i][j])
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};
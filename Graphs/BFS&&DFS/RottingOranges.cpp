#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/rotting-oranges/description/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q;
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};

        int countFresh = 0;
        int newCount = 0;
        int answer = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }

                if (grid[i][j] == 1)
                {
                    countFresh++;
                }
            }
        }

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int time = it.second;

            answer = max(time, answer);

            for (int k = 0; k < 4; k++)
            {
                int nrow = i + row[k];
                int ncol = j + col[k];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, time + 1});
                    visited[nrow][ncol] = 2;
                    newCount++;
                }
            }
        }

        if (countFresh != newCount)
        {
            return -1;
        }

        return answer;
    }
};
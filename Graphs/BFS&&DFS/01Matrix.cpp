#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q;
        vector<int> moveRow = {0, 0, 1, -1};
        vector<int> moveCol = {1, -1, 0, 0};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int oldDistance = it.second;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + moveRow[i];
                int ncol = col + moveCol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol])
                {
                    int newDistance = oldDistance + 1;
                    visited[nrow][ncol] = 1;
                    distance[nrow][ncol] = newDistance;
                    q.push({{nrow, ncol}, newDistance});
                }
            }
        }

        return distance;
    }
};
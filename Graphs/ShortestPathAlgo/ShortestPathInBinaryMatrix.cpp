#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>

using namespace std;

// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        queue<pair<int, int>> q;
        int answer = 1;
        vector<int> newRow = {-1, 1, 0, 0, -1, 1, -1, 1};
        vector<int> newCol = {0, 0, -1, 1, -1, 1, 1, -1};

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto it = q.front();
                int row = it.first;
                int col = it.second;
                q.pop();

                if (row == n - 1 && col == n - 1)
                    return answer;

                for (int i = 0; i < 8; i++)
                {
                    int nrow = row + newRow[i];
                    int ncol = col + newCol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0)
                    {
                        grid[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            answer++;
        }
        
        return -1;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/flood-fill/description/

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;

        vector<int> checkRow = {-1, 1, 0, 0};
        vector<int> checkCol = {0, 0, -1, 1};
        int oldColor = image[sr][sc];

        if (oldColor == color)
        {
            return image;
        }

        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;

            for (int i = 0; i < 4; i++)
            {
                int nrow = checkRow[i] + row;
                int ncol = checkCol[i] + col;

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == oldColor)
                {
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/triangle/description/

// Tabulation
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> v(n, vector<int>(n, 0));
        int answer = INT_MAX;

        v[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                int down = INT_MAX;
                if (j < i)
                    down = triangle[i][j] + v[i - 1][j];

                int diagonal = INT_MAX;
                if (j > 0)
                    diagonal = triangle[i][j] + v[i - 1][j - 1];

                v[i][j] = min(down, diagonal);
            }
        }

        for (int i = 0; i < n; i++)
        {
            answer = min(v[n - 1][i], answer);
        }

        return answer;
    }
};

// Memoization
class Solution2
{
public:
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &v, int &n)
    {
        if (i == n - 1)
            return triangle[i][j];

        if (v[i][j] != -1)
            return v[i][j];

        int down = triangle[i][j] + solve(i + 1, j, triangle, v, n);
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, v, n);

        return v[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> v(n, vector<int>(n, -1));

        return solve(0, 0, triangle, v, n);
    }
};
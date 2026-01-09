#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/minimum-falling-path-sum/description/

// Tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> v(n, vector<int>(n, 0));
        int answer = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            v[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = matrix[i][j] + v[i - 1][j];
                int leftD = INT_MAX;
                if (j > 0)
                    leftD = matrix[i][j] + v[i - 1][j - 1];
                int rightD = INT_MAX;
                if (j < n - 1)
                    rightD = matrix[i][j] + v[i - 1][j + 1];
                v[i][j] = min({up, leftD, rightD});
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
    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &v, int &n)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return 1e8;

        if (i == 0)
            return matrix[i][j];

        if (v[i][j] != -1)
            return v[i][j];

        int up = matrix[i][j] + solve(i - 1, j, matrix, v, n);
        int leftD = matrix[i][j] + solve(i - 1, j - 1, matrix, v, n);
        int rightD = matrix[i][j] + solve(i - 1, j + 1, matrix, v, n);

        return v[i][j] = min({up, leftD, rightD});
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int answer = INT_MAX;
        vector<vector<int>> v(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            int cellAnswer = solve(n - 1, i, matrix, v, n);
            answer = min(cellAnswer, answer);
        }

        return answer;
    }
};
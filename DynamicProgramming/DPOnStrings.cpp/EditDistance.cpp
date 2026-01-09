#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/edit-distance/description/

class Solution
{
public:
    int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &v)
    {
        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        if (v[i][j] != -1)
            return v[i][j];

        if (str1[i] == str2[j])
            return v[i][j] = solve(i - 1, j - 1, str1, str2, v);
        else
        {
            int remove = solve(i - 1, j, str1, str2, v);
            int add = solve(i, j - 1, str1, str2, v);
            int replace = solve(i - 1, j - 1, str1, str2, v);

            return v[i][j] = 1 + min({remove, add, replace});
        }
    }

    int minDistance(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> v(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, str1, str2, v);
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution
{
public:
    int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &v)
    {
        if (i < 0 || j < 0)
            return 0;

        if (str1[i] == str2[j])
            return 1 + solve(i - 1, j - 1, str1, str2, v);

        if (v[i][j] != -1)
            return v[i][j];

        int moveFirst = solve(i - 1, j, str1, str2, v);
        int moveSecond = solve(i, j - 1, str1, str2, v);

        return v[i][j] = max(moveFirst, moveSecond);
    }

    int longestCommonSubsequence(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> v(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, str1, str2, v);
    }
};
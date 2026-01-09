#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/wildcard-matching/description/

class Solution
{
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &v)
    {
        if (i < 0 && j < 0)
            return true;

        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (v[i][j] != -1)
            return v[i][j];

        if (p[j] == s[i] || p[j] == '?')
        {
            return v[i][j] = solve(i - 1, j - 1, s, p, v);
        }
        if (p[j] == '*')
        {
            return v[i][j] = solve(i, j - 1, s, p, v) || solve(i - 1, j, s, p, v);
        }

        return false;
    }

    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> v(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, s, p, v);
    }
};
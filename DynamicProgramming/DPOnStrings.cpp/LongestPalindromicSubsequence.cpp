#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        string str1 = s;
        string str2 = s;
        reverse(str2.begin(), str2.end());

        vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    v[i][j] = 1 + v[i - 1][j - 1];
                }
                else
                {
                    v[i][j] = max(v[i - 1][j], v[i][j - 1]);
                }
            }
        }

        return v[n][n];
    }
};
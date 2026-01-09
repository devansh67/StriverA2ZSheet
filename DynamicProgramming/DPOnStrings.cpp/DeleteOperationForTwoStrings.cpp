#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution
{
public:
    int minDistance(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
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

        int lcsValue = v[m][n];
        return ((m - lcsValue) + (n - lcsValue));
    }
};
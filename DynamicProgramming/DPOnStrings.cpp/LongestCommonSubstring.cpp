#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

// Tabulation
class Solution
{
public:
    int longestCommonSubstr(string &str1, string &str2)
    {
        int m = str1.length();
        int n = str2.length();
        int answer = 0;

        vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            v[i][0] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            v[0][i] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    v[i][j] = 1 + v[i - 1][j - 1];
                    answer = max(v[i][j], answer);
                }
                else
                {
                    v[i][j] = 0;
                }
            }
        }

        return answer;
    }
};

// Memoization
class Solution2
{
public:
    int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &v, int &answer)
    {
        if (i < 0 || j < 0)
            return 0;

        if (v[i][j] != -1)
            return v[i][j];

        int count = 0;
        if (str1[i] == str2[j])
        {
            count = 1 + solve(i - 1, j - 1, str1, str2, v, answer);
        }

        answer = max(count, answer);

        solve(i - 1, j, str1, str2, v, answer);
        solve(i, j - 1, str1, str2, v, answer);

        return v[i][j] = count;
    }

    int longestCommonSubstr(string &str1, string &str2)
    {
        int m = str1.length();
        int n = str2.length();
        int answer = INT_MIN;

        vector<vector<int>> v(m, vector<int>(n, -1));

        solve(m - 1, n - 1, str1, str2, v, answer);

        return answer;
    }
};
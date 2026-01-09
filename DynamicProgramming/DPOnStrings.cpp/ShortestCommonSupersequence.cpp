#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();
        string answer = "";

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

        int i = m;
        int j = n;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                answer += str1[i - 1];
                i--;
                j--;
            }
            else
            {
                if (v[i - 1][j] > v[i][j - 1])
                {
                    answer += str1[i - 1];
                    i--;
                }
                else
                {
                    answer += str2[j - 1];
                    j--;
                }
            }
        }

        while (i > 0)
        {
            answer.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0)
        {
            answer.push_back(str2[j - 1]);
            j--;
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};
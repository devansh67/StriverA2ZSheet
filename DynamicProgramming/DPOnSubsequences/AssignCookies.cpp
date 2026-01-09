#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/assign-cookies/description/

class Solution
{
public:
    int solve(int i, int j, vector<int> &student, vector<int> &cookie, vector<vector<int>> &v, int &m, int &n)
    {
        if (i >= m || j >= n)
            return 0;

        if (v[i][j] != -1)
            return v[i][j];

        int pick = INT_MIN;
        if (cookie[j] >= student[i])
            pick = 1 + solve(i + 1, j + 1, student, cookie, v, m, n);

        int notPick = solve(i, j + 1, student, cookie, v, m, n);

        return v[i][j] = max(pick, notPick);
    }

    int findContentChildren(vector<int> &student, vector<int> &cookie)
    {
        int m = student.size();
        int n = cookie.size();

        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        vector<vector<int>> v(m, vector<int>(n, -1));

        return solve(0, 0, student, cookie, v, m, n);
    }
};
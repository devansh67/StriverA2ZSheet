#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/geek-jump/1

class Solution
{
public:
    int solve(int i, vector<int> &height, vector<int> &v, int &n)
    {
        if (i == n - 1)
            return 0;

        if (v[i] != -1)
        {
            return v[i];
        }

        int left = INT_MAX;
        left = abs(height[i] - height[i + 1]) + solve(i + 1, height, v, n);
        int right = INT_MAX;
        if (i < n - 2)
            right = abs(height[i] - height[i + 2]) + solve(i + 2, height, v, n);

        return v[i] = min(left, right);
    }

    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> v(n, -1);

        return solve(0, height, v, n);
    }
};
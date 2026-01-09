#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution
{
public:
    int solve(int i, int prev, vector<int> &nums, int &n, vector<vector<int>> &v)
    {
        if (i == n)
            return 0;

        if (v[i][prev + 1] != -1)
            return v[i][prev + 1];

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev])
        {
            take = 1 + solve(i + 1, i, nums, n, v);
        }

        int notTake = solve(i + 1, prev, nums, n, v);

        return v[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> v(n, vector<int>(n + 1, -1));

        return solve(0, -1, nums, n, v);
    }
};
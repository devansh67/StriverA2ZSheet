#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/house-robber/description/

class Solution
{
public:
    int solve(int i, vector<int> &nums, vector<int> &v)
    {
        if (i < 0)
            return 0;
        if (i == 0)
            return nums[0];

        if (v[i] != -1)
        {
            return v[i];
        }

        int pick = nums[i] + solve(i - 2, nums, v);
        int notPick = solve(i - 1, nums, v);

        return v[i] = max(pick, notPick);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n, -1);

        return solve(n - 1, nums, v);
    }
};
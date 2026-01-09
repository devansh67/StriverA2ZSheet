#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/target-sum/description/

class Solution
{
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &v)
    {
        if (i == 0)
        {
            if (j == 0 && nums[i] == 0)
                return 2;

            if (j == 0 || nums[i] == j)
                return 1;
            else
                return 0;
        }

        if (v[i][j] != -1)
            return v[i][j];

        int pick = 0;
        if (nums[i] <= j)
            pick = solve(i - 1, j - nums[i], nums, v);

        int notPick = solve(i - 1, j, nums, v);

        return v[i][j] = (pick + notPick);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
        }
        if (sum - target < 0 || (sum - target) % 2 != 0)
            return 0;

        target = (sum - target) / 2;

        vector<vector<int>> v(n, vector<int>(target + 1, -1));

        return solve(n - 1, target, nums, v);
    }
};
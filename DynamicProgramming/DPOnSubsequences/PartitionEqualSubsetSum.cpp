#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution
{
public:
    bool solve(int i, int target, vector<int> &nums, vector<vector<int>> &v)
    {
        if (target == 0)
        {
            return true;
        }

        if (i == 0)
        {
            return nums[0] == target;
        }

        if (v[i][target] != -1)
            return v[i][target];

        bool pick = false;
        if (nums[i] <= target)
            pick = solve(i - 1, target - nums[i], nums, v);

        bool notPick = solve(i - 1, target, nums, v);

        return v[i][target] = pick || notPick;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;

        for (auto it : nums)
        {
            sum += it;
        }

        if (sum % 2 != 0)
            return false;

        vector<vector<int>> v(n, vector<int>(sum + 1, -1));
        int target = sum / 2;

        return solve(n - 1, target, nums, v);
    }
};
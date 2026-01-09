#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/house-robber-ii/description/

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

        vector<int> temp1;
        vector<int> temp2;

        if (n == 1)
            return nums[n-1];

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        int first = solve(n - 2, temp1, v);
        v.assign(n, -1);
        int second = solve(n - 2, temp2, v);

        return max(first, second);
    }
};
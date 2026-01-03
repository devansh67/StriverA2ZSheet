#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/jump-game/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxDistance = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > maxDistance)
            {
                return false;
            }

            maxDistance = max(i + nums[i], maxDistance);
            if (maxDistance > n)
                return true;
        }

        return true;
    }
};
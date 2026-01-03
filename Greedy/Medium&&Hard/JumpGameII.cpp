#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/jump-game-ii/description/

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int currEnd = 0;
        int maximumDistance = 0;
        int jumpCount = 0;

        for (int i = 0; i < n - 1; i++)
        {
            maximumDistance = max(i + nums[i], maximumDistance);

            if (i == currEnd)
            {
                jumpCount++;
                currEnd = maximumDistance;
            }
        }

        return jumpCount;
    }
};
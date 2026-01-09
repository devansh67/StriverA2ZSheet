#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Tabulation

class Solution
{
public:

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i++)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int len = v[i + 1][prev + 1];
                if (prev == -1 || nums[i] > nums[prev])
                {
                    len = max(1 + v[i + 1][i + 1], len);
                }
                v[i][prev + 1] = len;
            }
        }

        return v[0][0];
    }
};
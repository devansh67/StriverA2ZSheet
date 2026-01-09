#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;

        for (int x : nums)
            sum += x;

        int half = sum / 2;

        vector<vector<bool>> v(n, vector<bool>(half + 1, false));

        for (int i = 0; i < n; i++)
            v[i][0] = true;

        if (nums[0] <= half)
            v[0][nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= half; j++)
            {
                bool pick = false;
                if (nums[i] <= j)
                    pick = v[i - 1][j - nums[i]];

                bool notTake = v[i - 1][j];

                v[i][j] = pick || notTake;
            }
        }

        int answer = INT_MAX;
        for (int s1 = 0; s1 <= half; s1++)
        {
            if (v[n - 1][s1])
            {
                int diff = abs(sum - 2 * s1);
                answer = min(answer, diff);
            }
        }

        return answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution
{
public:
    bool solve(int divisor, vector<int> &nums, int threshold)
    {
        int sum = 0;
        for (auto it : nums)
        {
            sum += (it + divisor - 1) / divisor;
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int answer = 0;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        answer = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            bool isInThreshold = solve(mid, nums, threshold);

            if (isInThreshold)
            {
                answer = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return answer;
    }
};
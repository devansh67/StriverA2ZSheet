#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (k > n)
            return 0;

        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;

        long long current_sum = 0;
        long long maximum_sum = INT_MIN;

        while (j < n)
        {
            current_sum += nums[j];
            mp[nums[j]]++;

            if (j - i + 1 == k)
            {
                if (mp.size() == k)
                {
                    maximum_sum = max(current_sum, maximum_sum);
                }
                current_sum -= nums[i];
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return maximum_sum == INT_MIN ? 0 : maximum_sum;
    }
};

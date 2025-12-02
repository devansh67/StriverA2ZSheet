#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Kadane's Algorithm
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = nums[0];
        int answer = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (sum > nums[i])
            {
                sum = sum + nums[i];
            }
            else
            {
                sum = max(nums[i], sum + nums[i]);
            }
            answer = max(sum, answer);
        }
        return answer;
    }
};

// Alternate approach (easier to write)

class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr_sum = 0;
        int max_so_far_sum = INT_MIN;
        for (auto it : nums)
        {
            curr_sum = curr_sum + it;
            if (it > curr_sum)
            {
                curr_sum = it;
            }
            max_so_far_sum = max(max_so_far_sum, curr_sum);
        }
        return max_so_far_sum;
    }
};
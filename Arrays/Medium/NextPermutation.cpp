#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return;

        int i = 1;
        int lastPeak = -1;

        // Find the last peak
        while (i < n)
        {
            if (nums[i] > nums[i - 1])
            {
                lastPeak = i;
            }
            i += 1;
        }

        // If no last peak found it means the array is in descending order, sort and return
        if (lastPeak == -1)
        {
            for (i = 0; i < n / 2; i++)
            {
                swap(nums[i], nums[n - i - 1]);
            }
            return;
        }

        int presentPeakValue = nums[lastPeak];
        int index = lastPeak;

        for (int i = lastPeak; i < n; i++)
        {
            if (nums[i] > nums[lastPeak - 1] && nums[i] < nums[index])
            {
                index = i;
            }
        }
        swap(nums[lastPeak - 1], nums[index]);
        sort(nums.begin() + lastPeak, nums.end());
    }
};
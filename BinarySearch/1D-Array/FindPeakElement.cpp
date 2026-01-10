#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-peak-element/description/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            if (nums[mid] > nums[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};
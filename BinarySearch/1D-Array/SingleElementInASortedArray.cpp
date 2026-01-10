#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if (nums[mid] == nums[mid - 1])
            {
                if (mid % 2 != 0)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if (mid % 2 == 0)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int answer = INT_MAX;

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid])
            {
                answer = min(nums[low], answer);
                low = mid + 1;
            }
            else
            {
                answer = min(nums[mid], answer);
                high = mid - 1;
            }
        }

        return answer;
    }
};
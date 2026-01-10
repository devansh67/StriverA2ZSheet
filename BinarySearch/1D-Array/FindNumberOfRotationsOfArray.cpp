#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/rotation4723/1

class Solution
{
public:
    void findMin(vector<int> &nums, int &answer, int &n)
    {
        int minimumValue = INT_MAX;

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid])
            {
                if (nums[low] < minimumValue)
                {
                    minimumValue = nums[low];
                    answer = low;
                }
                low = mid + 1;
            }
            else
            {
                if (nums[mid] < minimumValue)
                {
                    minimumValue = nums[mid];
                    answer = mid;
                }
                high = mid - 1;
            }
        }
    }

    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();
        int minimumIndex = -1;

        findMin(arr, minimumIndex, n);

        return minimumIndex;
    }
};
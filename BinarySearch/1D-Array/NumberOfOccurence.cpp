#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

class Solution
{
public:
    int findFirstOccurence(vector<int> &nums, int &target, int &n)
    {
        int low = 0;
        int high = n - 1;
        int answer = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                answer = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return answer;
    }

    int findLastOccurence(vector<int> &nums, int &target, int &n)
    {
        int low = 0;
        int high = n - 1;
        int answer = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                answer = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return answer;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> answer;

        int firstOccurence = findFirstOccurence(nums, target, n);
        int lastOccurence = findLastOccurence(nums, target, n);

        answer.push_back(firstOccurence);
        answer.push_back(lastOccurence);

        return answer;
    }

    int countFreq(vector<int> &arr, int target)
    {
        vector<int> temp = searchRange(arr, target);

        return (temp[0] == -1 ? 0 : temp[1] - temp[0] + 1);
    }
};
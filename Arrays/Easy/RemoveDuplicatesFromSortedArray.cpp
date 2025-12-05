#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int currentNumber = nums[0];
        int currentIndex = 1;

        for (int i = 1; i < n; i++)
        {
            if (currentNumber == nums[i])
            {
                continue;
            }
            else
            {
                currentNumber = nums[i];
                swap(nums[i], nums[currentIndex]);
                currentIndex++;
            }
        }
        return currentIndex;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();

        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                count++;
            }

            if (count > 1)
            {
                return false;
            }
        }
        if (nums[n - 1] > nums[0])
        {
            count++;
        }
        return count <= 1;
    }
};
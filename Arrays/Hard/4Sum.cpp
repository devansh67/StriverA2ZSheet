#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                for (int j = i; j < n - 2; j++)
                {
                    if(j == 0 || (j > 0 && nums[j] != nums[j - 1]))
                    {
                        int start = nums[j+1];
                        int end = nums[n-1];
                    }
                }
            }
        }
    }
};
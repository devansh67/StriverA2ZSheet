#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int start = j + 1;
                int end = n - 1;

                long long updatedSum = (long long)target - (long long)nums[i] - (long long)nums[j];
                while (start < end)
                {
                    if (nums[start] + nums[end] < updatedSum)
                    {
                        start++;
                    }
                    else if (nums[start] + nums[end] > updatedSum)
                    {
                        end--;
                    }
                    else
                    {
                        s.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    }
                }
            }
        }

        for (auto it : s)
        {
            answer.push_back(it);
        }

        return answer;
    }
};
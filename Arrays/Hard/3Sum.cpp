#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if ((i == 0) || (i > 0 && nums[i] != nums[i - 1]))
            {
                int start = i + 1;
                int end = n - 1;

                while (start < end)
                {
                    int currentSum = nums[i] + nums[start] + nums[end];
                    if (currentSum == 0)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        answer.push_back(temp);

                        while (start < end && nums[start] == nums[start + 1])
                        {
                            start++;
                        }

                        while (start < end && nums[end] == nums[end - 1])
                        {
                            end--;
                        }
                        start++;
                        end--;
                    }
                    else if (currentSum < 0)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
            }
        }
        return answer;
    }
};
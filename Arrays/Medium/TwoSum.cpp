#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> answer;

        for (int i = 0; i < n; i++)
        {
            int expectedNumber = target - nums[i];
            if (mp.find(expectedNumber) == mp.end())
            {
                mp.insert({nums[i], i});
            }
            else
            {
                answer.push_back(mp[expectedNumber]);
                answer.push_back(i);
                break;
            }
        }
        return answer;
    }
};
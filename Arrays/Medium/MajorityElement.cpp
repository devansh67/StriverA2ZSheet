#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findCandidateElement(vector<int> nums)
    {
        int n = nums.size();
        int presentCandidate = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == presentCandidate)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    presentCandidate = nums[i];
                    count++;
                }
            }
        }
        return presentCandidate;
    }

    bool isCandidateMajority(vector<int> nums, int candidateElement)
    {
        int n = nums.size();
        int occurenceCount = 0;

        for (auto it : nums)
        {
            if (it == candidateElement)
            {
                occurenceCount++;
            }
        }
        if (occurenceCount > n / 2)
        {
            return true;
        }
        return false;
    }

    int majorityElement(vector<int> &nums)
    {
        int candidateElement = findCandidateElement(nums);
        bool isMajority = isCandidateMajority(nums, candidateElement);
        return isMajority ? candidateElement : -1;
    }
};
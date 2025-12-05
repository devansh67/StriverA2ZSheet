#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();

        unordered_map<int, int> mp;
        int currentSum = 0;
        int maximumLength = 0;

        for (int i = 0; i < n; i++)
        {
            currentSum += arr[i];
            if (currentSum == k)
            {
                maximumLength = i + 1;
            }
            if (mp.find(currentSum - k) != mp.end())
            {
                maximumLength = max(i - mp[currentSum - k], maximumLength);
            }

            if(mp.find(currentSum) == mp.end())
            {
                mp[currentSum] = i;
            }
        }
        return maximumLength;
    }
};
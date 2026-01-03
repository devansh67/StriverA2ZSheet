#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        int m = arr.size();
        int n = dep.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 1;
        int j = 0;

        int maxPlatformsCount = 1;
        int currPlatformCount = 1;

        while (i < m && j < n)
        {
            if (arr[i] <= dep[j])
            {
                currPlatformCount++;
                i++;
                maxPlatformsCount = max(currPlatformCount, maxPlatformsCount);
            }
            else
            {
                currPlatformCount--;
                j++;
            }
        }

        return maxPlatformsCount;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        int n = arr.size();
        int currentSum = 0;
        int maximumLength = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            currentSum = currentSum + arr[i];
            if (currentSum == 0)
            {
                maximumLength = i + 1;
            }
            else if (mp.find(currentSum) != mp.end())
            {
                maximumLength = max(i - mp[currentSum], maximumLength);
            }
            else
            {
                mp[currentSum] = i;
            }
        }
        return maximumLength;
    }
};
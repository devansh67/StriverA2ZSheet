#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        long long sum = 0;

        unordered_map<long long, int> mp;
        int answer = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == k)
            {
                answer = i+1;
            }
            else
            {
                int difference = sum - k;
                if (mp.find(difference) != mp.end())
                {
                    answer = max(i - mp[difference], answer);
                }
            }

            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }

        }
        return answer == INT_MIN ? 0 : answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 0;
        int j = 0;

        if (k > n)
            return 0;

        int current_sum = 0;
        int maximum_sum = INT_MIN;

        while (j < n)
        {
            current_sum += arr[j];
            if (j - i + 1 == k)
            {
                maximum_sum = max(current_sum, maximum_sum);
                current_sum -= arr[i];
                i++;
            }
            j++;
        }
        return maximum_sum == INT_MIN ? 0 : maximum_sum;
    }
};
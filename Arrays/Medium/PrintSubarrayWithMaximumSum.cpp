#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Kadane's Algorithm
class Solution
{
public:
    void maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = nums[0];
        int answer = nums[0];
        int currStart = 0;
        int bestStart = 0;
        int bestEnd = 0;

        for (int i = 1; i < n; i++)
        {
            if (sum + nums[i] >= nums[i])
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
                currStart = i;
            }

            if (sum > answer)
            {
                answer = sum;
                bestStart = currStart;
                bestEnd = i;
            }
        }

        for (int i = bestStart; i <= bestEnd; i++)
        {
            cout << nums[i] << "";
        }
        cout << endl;
    }
};
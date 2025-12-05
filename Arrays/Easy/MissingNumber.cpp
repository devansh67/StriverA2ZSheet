#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        int xor1 = 0;
        int xor2 = 0;

        for (int i = 0; i < n; i++)
        {
            xor1 = xor1 ^ nums[i];
            xor2 = xor2 ^ (i + 1);
        }
        return xor1 ^ xor2;
    }
};

class Solution2
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int currentSum = 0;
        long totalSum = long((n * (n + 1)) / 2);
        for (auto it : nums)
        {
            currentSum += it;
        }
        return totalSum - currentSum;
    }
};
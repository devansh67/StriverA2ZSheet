#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        int xorValue = 0;
        for (auto it : nums)
        {
            xorValue = xorValue ^ it;
        }
        return xorValue;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int currentNumber = 0;
        int maximumNumber = INT_MIN;

        for (auto it : nums)
        {
            if (it == 1)
            {
                currentNumber++;
                maximumNumber = max(currentNumber, maximumNumber);
            }
            else
            {
                currentNumber = 0;
            }
        }
        maximumNumber = max(currentNumber, maximumNumber);
        return maximumNumber == INT_MIN ? 0 : maximumNumber;
    }
};
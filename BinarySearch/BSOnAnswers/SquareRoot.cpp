#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/square-root/1

class Solution
{
public:
    int floorSqrt(int n)
    {
        int low = 1;
        int high = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int val = mid * mid;

            if (val <= n)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

class Solution
{
public:
    int nthRoot(int n, int m)
    {
        int low = 1;
        int high = m;

        if(m == 0) return 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long val = pow(mid, n);

            if (val == m)
                return mid;

            if (val < m)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};
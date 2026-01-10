#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution
{
public:
    long long solve(vector<int> &piles, int speed)
    {
        long long time = 0;
        for (int it : piles)
        {
            time += (it + speed - 1) / speed; // ceil without double
        }
        return time;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int answer = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            long long hours = solve(piles, mid);

            if (hours <= h)
            {
                answer = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return answer;
    }
};
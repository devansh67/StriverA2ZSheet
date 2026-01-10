#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution
{
public:
    bool solve(int totalWt, vector<int> &weights, int days)
    {
        int currWt = 0;
        int numDays = 1;

        for (auto it : weights)
        {
            if (currWt + it <= totalWt)
            {
                currWt += it;
            }
            else
            {
                numDays++;
                currWt = it;
            }
        }

        return numDays <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int answer = 0;

        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for (auto it : weights)
        {
            high += it;
        }
        answer = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (solve(mid, weights, days))
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
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution
{
public:
    int solve(vector<int> &bloomDay, int m, int countSet, int day)
    {
        int currBloomed = 0;
        int countBouqet = 0;

        for (auto it : bloomDay)
        {
            if (day >= it)
            {
                currBloomed++;
            }
            else
            {
                countBouqet += currBloomed / countSet;
                currBloomed = 0;
            }
        }

        countBouqet += currBloomed / countSet;

        return countBouqet >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());

        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int answer = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            bool possible = solve(bloomDay, m, k, mid);

            if (possible)
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
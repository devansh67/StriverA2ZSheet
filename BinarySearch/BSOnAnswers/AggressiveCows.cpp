#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
    bool solve(int maxDistance, vector<int> &stalls, int k)
    {
        int countCows = 1;
        int last = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= maxDistance)
            {
                countCows++;
                last = stalls[i];
            }

            if (countCows >= k)
                return true;
        }

        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        int answer = 0;
        sort(stalls.begin(), stalls.end());

        int minElement = stalls[0];
        int maxElement = stalls[n - 1];
        int low = 1;
        int high = maxElement - minElement;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (solve(mid, stalls, k))
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return answer;
    }
};
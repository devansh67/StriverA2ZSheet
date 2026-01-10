#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/implement-upper-bound/1

class Solution
{
public:
    int upperBound(vector<int> &arr, int target)
    {
        int n = arr.size();
        int answer = n;

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > target)
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

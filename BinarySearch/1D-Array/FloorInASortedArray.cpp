#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

class Solution
{
public:
    int findFloor(vector<int> &arr, int x)
    {
        int n = arr.size();
        int answer = -1;

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
            {
                answer = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution
{
public:
    bool solve(int lotSize, vector<int> &arr, int k)
    {
        int numStudents = 1;
        int currPageCount = 0;

        for (auto it : arr)
        {
            if (currPageCount + it <= lotSize)
            {
                currPageCount += it;
            }
            else
            {
                numStudents++;
                currPageCount = it;
            }
        }

        return numStudents <= k;
    }

    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();
        int sum = 0;
        int answer = 0;

        if (k > n)
            return -1;

        for (auto it : arr)
        {
            sum += it;
        }

        int low = *max_element(arr.begin(), arr.end());
        int high = sum;
        answer = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (solve(mid, arr, k))
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
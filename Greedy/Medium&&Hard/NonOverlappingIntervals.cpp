#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/non-overlapping-intervals/

class Solution
{
public:
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comparator);
        int currEnd = intervals[0][1];
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < currEnd)
            {
                count++;
            }
            else
            {
                currEnd = intervals[i][1];
            }
        }

        return count;
    }
};
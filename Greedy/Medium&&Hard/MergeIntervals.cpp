#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/merge-intervals/description/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int current_start = intervals[0][0];
        int current_end = intervals[0][1];
        vector<vector<int>> answer;

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= current_end)
            {
                current_end = max(intervals[i][1], current_end);
            }
            else
            {
                answer.push_back({current_start, current_end});
                current_start = intervals[i][0];
                current_end = intervals[i][1];
            }
        }
        answer.push_back({current_start, current_end});

        return answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

class Solution
{
public:
    static bool comparator(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }

    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        int n = start.size();
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
        {
            arr.push_back({start[i], finish[i]});
        }

        sort(arr.begin(), arr.end(), comparator);

        int count = 0;
        int currEnd = INT_MIN;

        for (auto it : arr)
        {
            if (it.first > currEnd)
            {
                count++;
                currEnd = it.second;
            }
        }

        return count;
    }
};
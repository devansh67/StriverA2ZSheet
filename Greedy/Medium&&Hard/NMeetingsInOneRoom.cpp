#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
public:
    static bool comparator(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();
        int count = 0;
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
        {
            arr.push_back({start[i], end[i]});
        }

        sort(arr.begin(), arr.end(), comparator);

        count = 1;
        int currEnd = arr[0].second;

        for(int i = 1; i < n; i++)
        {
            auto it =  arr[i];
            if(it.first > currEnd)
            {
                count++;
                currEnd = it.second;
            }
        }
        return count;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

class Solution
{
public:
    static bool comparator(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
    {
        return a.first.second < b.first.second;
    }

    vector<int> maxMeetings(int n, vector<int> &start, vector<int> &end)
    {
        vector<pair<pair<int, int>, int>> arr;
        vector<int> answer;

        int currEnd = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            arr.push_back({{start[i], end[i]}, i+1});
        }

        sort(arr.begin(), arr.end(), comparator);

        for (auto it : arr)
        {
            if (it.first.first > currEnd)
            {
                answer.push_back(it.second);
                currEnd = it.first.second;
            }
        }
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};
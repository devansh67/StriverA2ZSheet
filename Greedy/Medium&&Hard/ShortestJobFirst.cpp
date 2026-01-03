#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-job-first/1

class Solution
{
public:
    long long solve(vector<int> &arr)
    {
        int n = arr.size();

        int curr_time = 0;
        long long answer = 0;

        sort(arr.begin(), arr.end());

        for (auto it : arr)
        {
            answer += curr_time;
            curr_time += it;
        }

        return (long long)answer / (long long)n;
    }
};
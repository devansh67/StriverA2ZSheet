#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/geeks-training/1

// Tabulation
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> v(n, vector<int>(4, 0));

        // Base case: day 0
        v[0][0] = max(arr[0][1], arr[0][2]);
        v[0][1] = max(arr[0][0], arr[0][2]);
        v[0][2] = max(arr[0][0], arr[0][1]);
        v[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

        for (int day = 1; day < n; day++)
        {
            for (int prev = 0; prev < 4; prev++)
            {
                v[day][prev] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != prev)
                    {
                        int newPoint = arr[day][task] + v[day - 1][task];
                        v[day][prev] = max(v[day][prev], newPoint);
                    }
                }
            }
        }

        return v[n - 1][3];
    }
};


// Memoization
class Solution2
{
public:
    int solve(int index, int prevTask, vector<vector<int>> &arr, vector<vector<int>> &v)
    {
        if (v[index][prevTask] != -1)
        {
            return v[index][prevTask];
        }

        if (index == 0)
        {
            int points = INT_MIN;
            for (int i = 0; i < 3; i++)
            {
                if (i != prevTask)
                {
                    points = max(arr[index][i], points);
                }
            }

            return v[index][prevTask] = points;
        }

        int points = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != prevTask)
            {
                int newPoints = arr[index][i] + solve(index - 1, i, arr, v);
                points = max(newPoints, points);
            }
        }

        return v[index][prevTask] = points;
    }

    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> v(n, vector<int>(4, -1));

        return solve(n - 1, 3, arr, v);
    }
};
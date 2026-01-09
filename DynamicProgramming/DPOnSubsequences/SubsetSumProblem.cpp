#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution
{
public:
    bool solve(int i, int target, vector<int> &arr, vector<vector<int>> &v)
    {

        if (target == 0)
            return true;
            
        if (i == 0)
            return arr[0] == target;

        if (v[i][target] != -1)
            return v[i][target];

        bool pick = false;
        if (arr[i] <= target)
            pick = solve(i - 1, target - arr[i], arr, v);

        bool notPick = solve(i - 1, target, arr, v);

        return v[i][target] = pick || notPick;
    }

    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> v(n, vector<int>(sum + 1, -1));

        return solve(n - 1, sum, arr, v);
    }
};
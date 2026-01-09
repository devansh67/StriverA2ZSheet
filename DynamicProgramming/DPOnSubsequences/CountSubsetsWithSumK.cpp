#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution
{
public:
    const int MOD = 1e9 + 7;

    int solve(int i, int target, vector<int> &arr, vector<vector<int>> &v)
    {
        if (i == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || arr[0] == target)
                return 1;
            return 0;
        }

        if (v[i][target] != -1)
            return v[i][target];

        int pick = 0;
        if (arr[i] <= target)
            pick = solve(i - 1, target - arr[i], arr, v);
        int notPick = solve(i - 1, target, arr, v);

        return v[i][target] = (pick + notPick) % MOD;
    }

    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> v(n, vector<int>(target + 1, -1));

        return solve(n - 1, target, arr, v);
    }
};
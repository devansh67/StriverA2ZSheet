#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;

    int solve(int i, int target, vector<int> &arr, vector<vector<int>> &v)
    {
        if (i == 0)
        {
            if (target == 0 && arr[0] == 0)
            {
                return 2;
            }
            if (target == 0 || arr[0] == target)
            {
                return 1;
            }
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

    int countPartitions(vector<int> &arr, int diff)
    {
        int n = arr.size();
        int sum = 0;

        for (auto it : arr)
        {
            sum += it;
        }

        if (sum - diff < 0 || (sum - diff) % 2 != 0)
            return 0;
        int requiredSum = (sum - diff) / 2;

        vector<vector<int>> v(n, vector<int>(requiredSum + 1, -1));

        return solve(n - 1, requiredSum, arr, v);
    }
};
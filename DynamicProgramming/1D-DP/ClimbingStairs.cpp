#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/climbing-stairs/

class Solution
{
public:
    int solve(int i, vector<int> &v)
    {
        if (i <= 2)
        {
            return i;
        }

        if (v[i] != -1)
            return v[i];

        return v[i] = solve(i - 2, v) + solve(i - 1, v);
    }

    int climbStairs(int n)
    {
        vector<int> v(n+1, -1);
        return solve(n, v);
    }
};
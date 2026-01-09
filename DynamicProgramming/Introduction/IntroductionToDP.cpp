#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/introduction-to-dp/1

long long int mod = 1e9 + 7;

class Solution
{
public:
    long long int solve(vector<long long> &v, int n)
    {
        if (n <= 1)
            return n;

        if (v[n] != -1)
        {
            return v[n] % mod;
        }
        return v[n] = (solve(v, n - 1) + solve(v, n - 2)) % mod;
    }

    long long int topDown(int n)
    {
        vector<long long> v(n + 1, -1);
        return solve(v, n);
    }

    long long int bottomUp(int n)
    {
        vector<long long> v(n+1, 0);
        v[0] = 0;
        if (n >= 1)
            v[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            v[i] = (v[i - 1] + v[i - 2]) % mod;
        }

        return v[n];
    }
};
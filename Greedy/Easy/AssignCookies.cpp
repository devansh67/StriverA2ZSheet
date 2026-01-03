#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/assign-cookies/description/

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        int count = 0;

        for (auto it : g)
        {
            if (i == n)
            {
                break;
            }

            if (it <= s[i])
            {
                count++;
            }
            else
            {
                while (i < n && it > s[i])
                {
                    i++;
                }
                if (i < n)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            i++;
        }

        return count;
    }
};
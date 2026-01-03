#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        int i = 0;
        int j = 0;

        unordered_map<char, int> mp;
        int start = 0;
        int minimum = INT_MAX;

        for (auto it : t)
        {
            mp[it]++;
        }

        int count = mp.size();

        while (j < m)
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;

                if (mp[s[j]] == 0)
                {
                    count--;
                }
            }

            while (count == 0)
            {
                if (minimum > j - i + 1)
                {
                    minimum = j - i + 1;
                    start = i;
                }

                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                    {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return minimum == INT_MAX ? "" : s.substr(start, minimum);
    }
};
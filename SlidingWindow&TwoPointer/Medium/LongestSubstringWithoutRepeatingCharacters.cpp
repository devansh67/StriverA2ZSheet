#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int i = 0;
        int j = 0;

        unordered_map<char, int> mp;
        int answer = INT_MIN;

        while (j < n)
        {
            mp[s[j]]++;
            if (mp[s[j]] == 1)
            {
                answer = max(j - i + 1, answer);
            }
            else
            {
                while (mp[s[j]] > 1)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return answer == INT_MIN ? 0 : answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.length();
        unordered_map<char, int> mp;

        int i = 0;
        int j = 0;
        int answer = INT_MIN;

        while (j < n)
        {
            mp[s[j]]++;

            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }

            if (mp.size() == k)
            {
                answer = max(j - i + 1, answer);
            }
            j++;
        }
        
        return answer == INT_MIN ? -1 : answer;
    }
};
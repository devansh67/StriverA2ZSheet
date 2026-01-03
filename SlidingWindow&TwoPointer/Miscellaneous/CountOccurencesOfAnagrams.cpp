#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution
{
public:
    int search(string &pat, string &txt)
    {
        unordered_map<char, int> mp;
        int n = txt.length();
        int i = 0;
        int j = 0;

        for (auto it : pat)
        {
            mp[it]++;
        }

        int count = mp.size();
        int k = pat.length();

        int answer = 0;

        while (j < n)
        {
            if (mp.find(txt[j]) != mp.end())
            {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0)
                {
                    count--;
                }
            }

            if (j - i + 1 < k)
            {
                j++;
            }
            else if(j - i + 1 == k)
            {
                if (count == 0)
                {
                    answer++;
                }
                if (mp.find(txt[i]) != mp.end())
                {
                    mp[txt[i]]++;
                    if (mp[txt[i]] == 1)
                    {
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return answer;
    }
};
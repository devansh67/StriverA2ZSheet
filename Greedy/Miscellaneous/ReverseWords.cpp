#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

class Solution
{
public:

    string reverseWords(string &s)
    {
        int n = s.length();
        reverse(s.begin(), s.end());

        int start = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                if (start < i)
                {
                    reverse(s.begin() + start, s.begin() + i);
                }
                start = i + 1;
            }
        }
        reverse(s.begin() + start, s.end());

        int write = 0;
        bool dotAllowed = false;

        for (int read = 0; read < s.size(); read++)
        {
            if (s[read] != '.')
            {
                s[write++] = s[read];
                dotAllowed = true;
            }
            else if (dotAllowed)
            {
                s[write++] = '.';
                dotAllowed = false;
            }
        }

        // remove trailing dot if exists
        if (write > 0 && s[write - 1] == '.')
            write--;

        s.resize(write);

        return s;
    }
};
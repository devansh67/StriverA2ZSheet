#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/valid-parenthesis-string/

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length();
        int minimum = 0;
        int maximum = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                minimum += 1;
                maximum += 1;
            }
            else if (s[i] == ')')
            {
                minimum -= 1;
                maximum -= 1;
            }
            else
            {
                minimum = minimum - 1;
                maximum = maximum + 1;
            }

            if (minimum < 0)
            {
                minimum = 0;
            }
            if (maximum < 0)
            {
                return false;
            }
        }

        return (minimum == 0);
    }
};
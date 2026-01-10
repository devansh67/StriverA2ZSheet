#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        stack<int> st;

        for (auto it : s)
        {
            if (it == '(' || it == '[' || it == '{')
            {
                st.push(it);
            }
            else if (st.empty())
                return false;
            else if (it == ')')
            {
                if (st.top() != '(')
                    return false;
                st.pop();
            }
            else if (it == ']')
            {
                if (st.top() != '[')
                    return false;
                st.pop();
            }
            else if (it == '}')
            {
                if (st.top() != '{')
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
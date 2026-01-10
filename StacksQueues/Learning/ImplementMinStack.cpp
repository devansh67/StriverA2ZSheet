#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://leetcode.com/problems/min-stack/

class MinStack
{
public:
    stack<long long> st;
    long long minElement;

    MinStack()
    {
        minElement = LONG_MAX;
    }

    void push(int val)
    {
        long long temp = (long long)val;
        if (st.empty())
        {
            minElement = val;
            st.push(val);
        }
        else
        {
            if (val > minElement)
                st.push(val);
            else
            {
                st.push(2 * val - minElement);
                minElement = val;
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        long long val = st.top();
        st.pop();

        if (val < minElement)
        {
            minElement = 2 * minElement - val;
        }
    }

    int top()
    {
        long long temp = st.top();
        if (temp < minElement)
        {
            return int(minElement);
        }

        return int(temp);
    }

    int getMin()
    {
        return int(minElement);
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        vector<int> leftsmall(n + 1);
        vector<int> rightsmall(n + 1);

        for (int i = 0; i < n; i++)
        {
            while (!(st.empty()) && heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                leftsmall[i] = 0;
            }
            else
            {
                leftsmall[i] = st.top() + 1;
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!(st.empty()) && heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                rightsmall[i] = n - 1;
            }
            else
            {
                rightsmall[i] = st.top() - 1;
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }

        return ans;
    }
};
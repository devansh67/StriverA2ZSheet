#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> answer(n, -1);

        // traverse twice for circular behavior
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int idx = i % n;

            while (!st.empty() && st.top() <= nums[idx])
            {
                st.pop();
            }

            if (i < n)
            {
                if (!st.empty())
                    answer[idx] = st.top();
                else
                    answer[idx] = -1;
            }

            st.push(nums[idx]);
        }

        return answer;
    }
};

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://leetcode.com/problems/next-greater-element-i/description/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> mp;
        int n = nums2.size();
        vector<int> answer;

        int i = n - 1;

        while (i >= 0)
        {
            if (st.empty())
                st.push(nums2[i]);
            else if (st.top() <= nums2[i])
            {
                while (!st.empty() && st.top() <= nums2[i])
                {
                    st.pop();
                };
                if (!st.empty())
                    mp[nums2[i]] = st.top();
                else
                    mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            else
            {
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
            i--;
        }

        for (auto it : nums1)
        {
            if (mp.find(it) != mp.end())
            {
                answer.push_back(mp[it]);
            }
            else
            {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};
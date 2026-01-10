#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

class Solution
{
public:
    vector<int> nextSmallerEle(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;

        vector<int> answer;

        int i = n - 1;

        while (i >= 0)
        {
            if (st.empty())
            {
                answer.push_back(-1);
            }
            else if (st.top() < arr[i])
            {
                answer.push_back(st.top());
            }
            else
            {
                while (!st.empty() && st.top() >= arr[i])
                {
                    st.pop();
                }
                if (st.empty())
                    answer.push_back(-1);
                else
                    answer.push_back(st.top());
            }
            st.push(arr[i]);
            i--;
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};
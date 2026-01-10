#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://leetcode.com/problems/asteroid-collision/

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        stack<int> st;
        vector<int> answer;

        int i = n - 1;

        while (i >= 0)
        {
            if (!st.empty() && asteroids[i] > 0 && st.top() < 0)
            {
                if (abs(asteroids[i]) > abs(st.top()))
                {
                    // Naya wala (+ve) bada hai, stack wala (-ve) phat gaya
                    st.pop();
                    // i-- nahi karenge kyunki asteroids[i] abhi bhi zinda hai,
                    // shayad stack ke agle element se takraye
                }
                else if (abs(asteroids[i]) == abs(st.top()))
                {
                    // Dono phat gaye
                    st.pop();
                    i--; // Dono khatam, ab agla asteroid dekho
                }
                else
                {
                    // Naya wala (+ve) chota tha, wo phat gaya
                    i--; // asteroids[i] khatam, agla check karo
                }
            }
            else
            {
                st.push(asteroids[i]);
                i--;
            }
        }

        while (!st.empty())
        {
            auto it = st.top();
            answer.push_back(it);
            st.pop();
        }

        return answer;
    }
};
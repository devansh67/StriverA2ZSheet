#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://leetcode.com/problems/online-stock-span/

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int answer = 1;

        while (!st.empty() && st.top().first <= price)
        {
            answer += st.top().second;
            st.pop();
        }

        st.push({price, answer});
        return answer;
    }
};
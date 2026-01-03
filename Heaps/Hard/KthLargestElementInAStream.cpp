#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest
{
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        num = k;
        for (auto it : nums)
        {
            pq.push(it);

            if (pq.size() > num)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > num)
        {
            pq.pop();
        }

        return pq.top();
    }
};

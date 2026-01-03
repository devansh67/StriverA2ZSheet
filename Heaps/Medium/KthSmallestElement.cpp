#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        int n = arr.size();
        priority_queue<int> pq;

        for (auto it : arr)
        {
            pq.push(it);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

class Solution
{
public:
    void nearlySorted(vector<int> &arr, int k)
    {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        int index = 0;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);

            if (pq.size() > k)
            {
                arr[index++] = pq.top();
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};

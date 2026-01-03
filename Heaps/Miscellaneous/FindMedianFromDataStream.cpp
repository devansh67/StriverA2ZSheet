#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<>> minheap;

    MedianFinder() {}

void addNum(int num)
{
    // Step 1: insert
    if (maxheap.empty() || num <= maxheap.top())
        maxheap.push(num);
    else
        minheap.push(num);

    // Step 2: rebalance
    if (maxheap.size() > minheap.size() + 1)
    {
        minheap.push(maxheap.top());
        maxheap.pop();
    }
    else if (minheap.size() > maxheap.size())
    {
        maxheap.push(minheap.top());
        minheap.pop();
    }
}

    double findMedian()
    {
        int left_size = maxheap.size();
        int right_size = minheap.size();

        if (left_size > right_size)
        {
            return double(maxheap.top());
        }
        else
        {
            return (double(maxheap.top()) + double(minheap.top())) / 2;
        }
    }
};
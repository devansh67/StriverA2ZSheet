#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1

class Solution
{
public:
    long long findkthSmallestElement(long long arr[], long long k, long long n)
    {
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }

    long long sumBetweenTwoKth(long long arr[], long long n, long long k1, long long k2)
    {
        long long answer = 0;
        int A = findkthSmallestElement(arr, k1, n);
        int B = findkthSmallestElement(arr, k2, n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > A && arr[i] < B)
            {
                answer += arr[i];
            }
        }

        return answer;
    }
};
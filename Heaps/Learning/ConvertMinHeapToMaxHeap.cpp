#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1

class Solution
{
public:
    void heapify(vector<int> &arr, int i, int n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maximum = i;

        if (left < n && arr[left] > arr[maximum])
        {
            maximum = left;
        }

        if (right < n && arr[right] > arr[maximum])
        {
            maximum = right;
        }

        if (maximum != i)
        {
            swap(arr[i], arr[maximum]);
            heapify(arr, maximum, n);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int n)
    {
        for (int i = (n - 2) / 2; i >= 0; i--)
        {
            heapify(arr, i, n);
        }
    }
};
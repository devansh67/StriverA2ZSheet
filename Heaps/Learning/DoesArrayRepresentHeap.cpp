#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = 0; i < n - 2; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
            {
                if (arr[i] < arr[left])
                    return false;
            }

            if (right < n)
            {
                if (arr[i] < arr[right])
                    return false;
            }
        }

        return true;
    }
};
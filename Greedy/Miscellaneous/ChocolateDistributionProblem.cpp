#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution
{
public:
  int findMinDiff(vector<int> &arr, int m)
  {
    int n = arr.size();
    int i = 0;
    int j = m - 1;

    sort(arr.begin(), arr.end());
    int minimum = INT_MAX;
    while (j < n)
    {
      int difference = arr[j] - arr[i];
      minimum = min(difference, minimum);
      i++;
      j++;
    }

    return minimum;
  }
};
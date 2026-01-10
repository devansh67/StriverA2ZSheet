#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-a-peak-element-ii/description/

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int maxRow = 0;

            for (int row = 0; row < m; row++)
            {
                if (mat[row][mid] > mat[maxRow][mid])
                    maxRow = row;
            }
            int curr = mat[maxRow][mid];
            int leftElement = mid == 0 ? -1 : mat[maxRow][mid - 1];
            int rightElement = mid == n - 1 ? -1 : mat[maxRow][mid + 1];

            if (curr > leftElement && curr > rightElement)
                return {maxRow, mid};

            else if (curr < leftElement)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};
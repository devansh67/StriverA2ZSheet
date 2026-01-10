#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0)
        {
            int currElement = matrix[i][j];

            if (currElement == target)
                return true;

            else if (currElement < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return false;
    }
};
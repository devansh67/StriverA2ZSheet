#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        bool isZeroRowZero = false;
        bool isZeroColumnZero = false;

        // Check if any zeroes present in the zero column already and note that down
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                isZeroColumnZero = true;
                break;
            }
        }

        // Check if any zeroes present in the zero row already and note that down
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                isZeroRowZero = true;
                break;
            }
        }

        // Now the search area would be from (1,1) to (m-1, n-1) as the zero row and zero column case is noted and will be handled later
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0; // Set the corresponding zeroth row/column as zero to track the change to be made later
                }
            }
        }

        // Check for zeroes in zeroth column and make entire column zero
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Check for zeroes in zeroth row and make entire row zero
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // If zeroth row already had a zero make the entire zeroth row as zero
        if (isZeroRowZero)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }

        // If zeroth column already had a zero make the entire column as zero
        if (isZeroColumnZero)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
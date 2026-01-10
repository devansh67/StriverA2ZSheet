#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int i = 0;
        int j = m - 1;
https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
        while (i < j)
        {
            if (i != j)
            {
                if (mat[i][j] == 1)
                {
                    i++;
                }
                else if (mat[j][i] == 1)
                {
                    j--;
                }
                else
                {
                    i++;
                    j--;
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                if (mat[i][k] == 1 || mat[k][i] == 0)
                {
                    return -1;
                }
            }
        }

        return i;
    }
};
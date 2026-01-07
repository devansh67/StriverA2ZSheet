#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/number-of-provinces/description/

class Solution
{
public:
    void dfs(int i, vector<int> &visited, vector<vector<int>> &matrix, int &n)
    {
        visited[i] = 1;

        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1 && !visited[j])
            {
                dfs(j, visited, matrix, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int answer = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, matrix, n);
                answer++;
            }
        }

        return answer;
    }
};
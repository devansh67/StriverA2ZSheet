#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> answer;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                temp[j] = answer[i - 1][j] + answer[i - 1][j - 1];
            }
            answer.push_back(temp);
        }
        return answer;
    }
};
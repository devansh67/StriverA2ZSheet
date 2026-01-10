#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/row-with-maximum-ones/description/

class Solution
{
public:
    int findLowerBound(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int answer = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == 1)
            {
                answer = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return answer;
    }

    int rowWithMax1s(vector<vector<int>> &mat)
    {
        {
            int n = mat.size();
            vector<int> answer;
            int answerRow = 0;
            int answerCount = 0;

            for (int i = 0; i < n; i++)
            {
                int index = findLowerBound(mat[i]);
                int count = mat[i].size() - index;
                if (count > answerCount)
                {
                    answerCount = count;
                    answerRow = i;
                }
            }

            answer.push_back(answerRow);

            return answerRow;
        }
    }
};
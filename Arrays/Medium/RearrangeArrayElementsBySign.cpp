#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity:- O(n)
// Space complexity:- O(n)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        int positiveIndex = 0;
        int negativeIndex = 1;
        vector<int> answer(n, 0);

        for (auto it : nums)
        {
            if (it < 0)
            {
                answer[negativeIndex] = it;
                negativeIndex += 2;
            }
            else
            {
                answer[positiveIndex] = it;
                positiveIndex += 2;
            }
        }
        return answer;
    }
};

// Time complexity:- O(n)
// Space complexity:- O(n)
class Solution2
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> positives;
        vector<int> negatives;
        vector<int> answer;
        for (auto it : nums)
        {
            if (it < 0)
            {
                negatives.push_back(it);
            }
            else
            {
                positives.push_back(it);
            }
        }
        for (int i = 0; i < positives.size(); i++)
        {
            answer.push_back(positives[i]);
            answer.push_back(negatives[i]);
        }
        return answer;
    }
};
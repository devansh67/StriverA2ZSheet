#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int current_maximum = 1;
        int answer = 1;

        if (nums.size() == 0)
        {
            return 0;
        }

        unordered_set<int> s;

        for (auto it : nums)
        {
            s.insert(it);
        }

        for (auto it : s)
        {
            if (s.find(it - 1) == s.end())
            {
                int i = 1;
                while (s.find(it + i) != s.end())
                {
                    current_maximum = i + 1;
                    answer = max(current_maximum, answer);
                    i++;
                }
            }
        }
        return answer;
    }
};
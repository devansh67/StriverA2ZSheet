#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        list<int> linked_list;

        int i = 0;
        int j = 0;

        vector<int> answer;

        while (j < n)
        {
            while (!linked_list.empty() && linked_list.back() < nums[j])
            {
                linked_list.pop_back();
            }

            linked_list.push_back(nums[j]);

            if (j - i + 1 < k)
            {
                j++;
            }
            else
            {
                answer.push_back(linked_list.front());

                if (nums[i] == linked_list.front())
                {
                    linked_list.pop_front();
                }
                i++;
                j++;
            }
        }
        return answer;
    }
};
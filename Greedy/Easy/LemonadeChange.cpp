#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/lemonade-change/description/

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();

        int count_twenty = 0;
        int count_ten = 0;
        int count_five = 0;

        for (auto it : bills)
        {
            if (it == 20)
            {
                count_twenty++;
                if (count_ten >= 1 && count_five >= 1)
                {
                    count_ten--;
                    count_five--;
                }
                else if (count_five >= 3)
                {
                    count_five -= 3;
                }
                else
                {
                    return false;
                }
            }
            else if (it == 10)
            {
                count_ten++;
                if (count_five >= 1)
                {
                    count_five--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                count_five++;
            }
        }

        return true;
    }
};
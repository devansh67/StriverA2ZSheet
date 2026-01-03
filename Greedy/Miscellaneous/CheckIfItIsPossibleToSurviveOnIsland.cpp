#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

class Solution
{
public:
    int minimumDays(int surviveDay, int buyFood, int dayFood)
    {

        if (surviveDay >= 7 && (buyFood - dayFood) * 6 < dayFood)
        {
            return -1;
        }

        int sunday = surviveDay / 7;
        int answer = 0;

        int buyingDay = surviveDay - sunday;
        int totalFood = surviveDay * dayFood;

        if (totalFood % buyFood == 0)
        {
            answer = totalFood / buyFood;
        }
        else
        {
            answer = totalFood / buyFood + 1;
        }

        if (answer <= buyingDay)
        {
            return answer;
        }

        return -1;
    }
};
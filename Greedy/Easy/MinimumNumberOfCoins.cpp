#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

class Solution
{
public:
    int findMin(int n)
    {
        int count = 0;
        int current_money = n;

        int ten_count = current_money / 10;
        current_money -= ten_count * 10;

        int five_count = current_money / 5;
        current_money -= five_count * 5;

        int two_count = current_money / 2;
        current_money -= two_count * 2;

        count += ten_count + five_count + two_count + current_money;

        return count;
    }
};

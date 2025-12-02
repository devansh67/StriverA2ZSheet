#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        int n = arr.size();
        int current_maximum = INT_MIN;
        vector<int> answer;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= current_maximum)
            {
                answer.push_back(arr[i]);
                current_maximum = arr[i];
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
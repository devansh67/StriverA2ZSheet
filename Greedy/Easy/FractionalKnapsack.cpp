#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = wt.size();
        vector<pair<double, pair<int, int>>> temp; // Can use struct instead for better readability
        int current_capacity = capacity;
        double answer = 0.0;

        for (int i = 0; i < n; i++)
        {
            double valueByWeight = double(val[i]) / double(wt[i]);
            temp.push_back({valueByWeight, {val[i], wt[i]}});
        }

        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end()); // Can use custom comparator instead

        for (auto it : temp)
        {
            if (current_capacity == 0)
            {
                break;
            }
            if (it.second.second <= current_capacity)
            {
                answer += it.second.first;
                current_capacity -= it.second.second;
            }
            else
            {
                double maxPossibleValue = (double)(current_capacity) / (double)(it.second.second) * it.second.first;
                answer += maxPossibleValue;
                break;
            }
        }

        return answer;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> parent;

    // DSU find with path compression
    int findSlot(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findSlot(parent[x]);
    }

    static bool comparator(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first; // sort by profit descending
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // sort jobs by profit
        sort(jobs.begin(), jobs.end(), comparator);

        // initialize DSU
        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int countOfJobsCompleted = 0;
        int totalProfit = 0;

        for (auto &job : jobs)
        {
            int jobProfit = job.first;
            int jobDeadline = job.second;

            int availableSlot = findSlot(jobDeadline);

            if (availableSlot > 0)
            {
                // occupy this slot
                parent[availableSlot] = findSlot(availableSlot - 1);
                totalProfit += jobProfit;
                countOfJobsCompleted++;
            }
        }

        return {countOfJobsCompleted, totalProfit};
    }
};

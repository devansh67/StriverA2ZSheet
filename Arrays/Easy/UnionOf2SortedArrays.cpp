#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;

        vector<int> answer;

        while (i < m && j < n)
        {
            if (answer.size() > 0 && answer.back() == a[i])
            {
                i++;
                continue;
            }
            if (answer.size() > 0 && answer.back() == b[j])
            {
                j++;
                continue;
            }

            a[i] > b[j] ? answer.push_back(b[j++]) : answer.push_back(a[i++]);
        }

        if (answer.size() > 0)
        {
            while (i < m)
            {
                if (answer.back() != a[i])
                {
                    answer.push_back(a[i]);
                }
                i++;
            }

            while (j < n)
            {
                if (answer.back() != b[j])
                {
                    answer.push_back(b[j]);
                }
                j++;
            }
        }
        return answer;
    }
};
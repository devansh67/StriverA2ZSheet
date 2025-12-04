#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            int candidateElement1 = INT_MIN;
            int candidateElement2 = INT_MIN;

            int firstCount = 0, secondCount = 0;
            vector<int> answer;

            for(auto it: nums) {
                if(it == candidateElement1) {
                    firstCount++;
                }
                else if(it == candidateElement2) {
                    secondCount++;
                }
                else if(firstCount == 0) {
                    candidateElement1 = it;
                    firstCount++;
                }
                else if(secondCount == 0) {
                    candidateElement2 = it;
                    secondCount++;
                }
                else {
                    firstCount--;
                    secondCount--;
                }
            }

            firstCount = 0;
            secondCount = 0;

            for(auto it: nums)
            {
                if(it == candidateElement1)
                {
                    firstCount++;
                }
                else if(it == candidateElement2)
                {
                    secondCount++;
                }
            }
            if(firstCount > n/3) {
                answer.push_back(candidateElement1);
            }
            if(secondCount > n/3) {
                answer.push_back(candidateElement2);
            }
            return answer;
        }
    };
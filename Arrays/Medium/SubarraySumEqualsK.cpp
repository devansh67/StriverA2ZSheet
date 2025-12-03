#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int,int> mp;

            int currentSum = 0;
            int count = 0;

            for(int i = 0; i < n; i++) {
                currentSum += nums[i];

                if(currentSum == k) {
                    count ++;
                }
                
                if(mp.find(currentSum - k) != mp.end()) {
                    count += mp[currentSum - k];
                }

                mp[currentSum]++;
            }
            return count;
        }
    };
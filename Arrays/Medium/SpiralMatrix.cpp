#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            // Size of the matrix
            int m = matrix.size();
            int n = matrix[0].size();

            // Direction value that determines the direction we'll moving in
            int direction = 0;
            
            // Pointers on all 4 edges of boundaries of the matrix
            int top = 0;
            int bottom = m-1;
            int left = 0;
            int right = n-1;

            // Answer array
            vector<int> answer;

            while(top <= bottom && left <= right) {
                if(direction == 0) {
                    for(int i = left; i <= right; i++) {
                        answer.push_back(matrix[top][i]);
                    }
                    top++;
                }
                else if(direction == 1) {
                    for(int i = top; i <= bottom; i++) {
                        answer.push_back(matrix[i][right]);
                    }
                    right--;
                }
                else if(direction == 2) {
                    for(int i = right; i >= left; i--) {
                        answer.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }
                else if(direction == 3) {
                    for(int i = bottom; i >= top; i--) {
                        answer.push_back(matrix[i][left]);
                    }
                    left++;
                }
                direction = (direction + 1) % 4;
            }
            return answer;
        }
    };
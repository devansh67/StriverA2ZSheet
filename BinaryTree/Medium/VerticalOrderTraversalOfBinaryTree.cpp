#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    map<int, map<int, multiset<int>>> mp;
    void solve(TreeNode *curr, int row, int col)
    {
        if (curr == NULL)
        {
            return;
        }

        mp[col][row].insert(curr->val);
        solve(curr->left, row + 1, col - 1);
        solve(curr->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> answer;

        if (root == NULL)
        {
            return answer;
        }

        solve(root, 0, 0);

        for (auto col : mp)
        {
            vector<int> column;
            for (auto row : col.second)
            {
                for (int val : row.second)
                {
                    column.push_back(val);
                }
            }
            answer.push_back(column);
        }

        return answer;
    }
};
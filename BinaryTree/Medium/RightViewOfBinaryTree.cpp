#include <iostream>
#include <vector>
#include <unordered_map>
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
    void solve(TreeNode *root, int level, vector<int> &answer)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == answer.size())
        {
            answer.push_back(root->val);
        }

        solve(root->right, level + 1, answer);
        solve(root->left, level + 1, answer);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> answer;
        solve(root, 0, answer);

        return answer;
    }
};

class SolutionBfs
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> answer;

        if (root == NULL)
        {
            return answer;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();

                if (i == size - 1)
                {
                    answer.push_back(it->val);
                }

                if (it->left)
                {
                    q.push(it->left);
                }

                if (it->right)
                {
                    q.push(it->right);
                }
            }
        }

        return answer;
    }
};
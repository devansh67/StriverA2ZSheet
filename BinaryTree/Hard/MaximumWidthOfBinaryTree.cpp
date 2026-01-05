#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        long long answer = 1;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            long long size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;

            answer = max(end - start + 1, answer);

            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                long long index = it.second - start;

                q.pop();
                if (it.first->left != NULL)
                {
                    q.push({it.first->left, (long long)2 * index + 1});
                }

                if (it.first->right != NULL)
                {
                    q.push({it.first->right, (long long)2 * index + 2});
                }
            }
        }

        return answer;
    }
};
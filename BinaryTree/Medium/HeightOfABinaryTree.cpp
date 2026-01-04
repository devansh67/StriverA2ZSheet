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
    int solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = solve(root->left);
        int rh = solve(root->right);

        return 1 + max(lh, rh);
    }
    int maxDepth(TreeNode *root)
    {
        return solve(root);
    }
};
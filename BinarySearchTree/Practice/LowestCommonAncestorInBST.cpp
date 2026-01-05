#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

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
    TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root->val < p->val && root->val < q->val)
        {
            return solve(root->right, p, q);
        }
        else if (root->val > p->val && root->val > q->val)
        {
            return solve(root->left, p, q);
        }
        else
        {
            return root;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return solve(root, p, q);
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/symmetric-tree/description/

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
    bool solve(TreeNode *leftTree, TreeNode *rightTree)
    {
        if (leftTree == NULL && rightTree == NULL)
        {
            return true;
        }
        else if (leftTree == NULL || rightTree == NULL)
        {
            return false;
        }

        if (leftTree->val != rightTree->val)
        {
            return false;
        }
        bool it1 = solve(leftTree->left, rightTree->right);
        bool it2 = solve(leftTree->right, rightTree->left);

        return it1 && it2;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return solve(root->left, root->right);
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/same-tree/description/

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
    bool check(TreeNode *a, TreeNode *b)
    {
        if (a == NULL && b == NULL)
        {
            return true;
        }
        else if (a == NULL || b == NULL)
        {
            return false;
        }

        if (a->val != b->val)
        {
            return false;
        }

        bool left = check(a->left, b->left);
        bool right = check(a->right, b->right);

        return left && right;
    }

    bool isSameTree(TreeNode *a, TreeNode *b)
    {
        return check(a, b);
    }
};

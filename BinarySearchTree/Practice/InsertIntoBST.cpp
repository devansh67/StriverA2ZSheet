#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
    void solve(TreeNode *root, int &val)
    {
        if (root->val > val)
        {
            if (root->left == NULL)
            {
                root->left = new TreeNode(val);
            }
            else
            {
                solve(root->left, val);
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = new TreeNode(val);
            }
            else
            {
                solve(root->right, val);
            }
        }
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return new TreeNode(val);
        }
        solve(root, val);

        return root;
    }
};

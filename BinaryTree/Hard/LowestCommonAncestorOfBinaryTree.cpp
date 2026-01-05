#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

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

    TreeNode* solve(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == NULL || root->val == p->val || root->val == q->val)
        {
            return root;
        }

        auto leftNode = solve(root->left, p, q);
        auto rightNode = solve(root->right, p, q);

        if(leftNode && rightNode)
        {
            return root;
        }
        else if(leftNode)
        {
            return leftNode;
        }
        else
        {
            return rightNode;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return solve(root, p, q);
    }
};
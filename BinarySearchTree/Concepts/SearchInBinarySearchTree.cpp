#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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
    TreeNode *solve(TreeNode *root, int &val)
    {
        if (root == NULL)
        {
            return root;
        }

        TreeNode *answer = NULL;
        if (root->val == val)
        {
            answer = root;
        }
        else if (root->val > val)
        {
            answer = solve(root->left, val);
        }
        else
        {
            answer = solve(root->right, val);
        }

        return answer;
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        return solve(root, val);
    }
};
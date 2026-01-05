#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

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
    bool isBST(TreeNode* root, long long minimum, long long maximum)
    {
        if (!root) return true;

        if (root->val <= minimum || root->val >= maximum)
            return false;

        return isBST(root->left, minimum, root->val) &&
               isBST(root->right, root->val, maximum);
    }

    bool isValidBST(TreeNode* root)
    {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};

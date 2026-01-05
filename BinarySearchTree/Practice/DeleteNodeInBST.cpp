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
    TreeNode *minVal(TreeNode *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

    TreeNode *solve(TreeNode *root, int &key)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root->val == key)
        {
            // 0 child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // 1 child
            // left child
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // right child
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // 2 child
            if (root->left != NULL && root->right != NULL)
            {
                int minimum = minVal(root->right)->val;
                root->val = minimum;
                root->right = solve(root->right, minimum);
                return root;
            }
        }
        else if (root->val > key)
        {
            root->left = solve(root->left, key);
        }
        else
        {
            root->right = solve(root->right, key);
        }
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return solve(root, key);
    }
};
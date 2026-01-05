#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    void createMapping(vector<int> inorder, unordered_map<int, int> &mp, int n)
    {
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
    }

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &index, int inorderStart, int inorderEnd, unordered_map<int, int> &mp, int n)
    {
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = preorder[index++];
        TreeNode *root = new TreeNode(element);
        int pos = mp[element];

        root->left = solve(preorder, inorder, index, inorderStart, pos - 1, mp, n);
        root->right = solve(preorder, inorder, index, pos + 1, inorderEnd, mp, n);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        int preOrderIndex = 0;
        unordered_map<int, int> mp;
        createMapping(inorder, mp, n);

        return solve(preorder, inorder, preOrderIndex, 0, n - 1, mp, n);
    }
};

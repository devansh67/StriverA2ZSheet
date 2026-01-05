#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    void populateMap(unordered_map<int, int> &mp, vector<int> &inorder, int n)
    {
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &postorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &mp, int n)
    {
        if (postorderIndex < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = postorder[postorderIndex--];
        TreeNode *root = new TreeNode(element);
        int pos = mp[element];
        
        root->right = solve(inorder, postorder, postorderIndex, pos + 1, inorderEnd, mp, n);
        root->left = solve(inorder, postorder, postorderIndex, inorderStart, pos - 1, mp, n);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        int postorderIndex = n - 1;

        unordered_map<int, int> mp;
        populateMap(mp, inorder, n);

        return solve(inorder, postorder, postorderIndex, 0, n - 1, mp, n);
    }
};
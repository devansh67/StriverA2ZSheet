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
    int findHeight(TreeNode *root, bool isLeft)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = isLeft ? root->left : root->right;
        }

        return height;
    }

    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = findHeight(root, true);
        int rh = findHeight(root, false);

        if (lh == rh)
        {
            return pow(2, lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
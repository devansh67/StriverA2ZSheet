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
    void solve(vector<string> &answer, TreeNode *root, string temp)
    {
        if (root->left == NULL && root->right == NULL)
        {
            answer.push_back(temp);
            return;
        }

        if (root->left)
        {
            solve(answer, root->left, temp + "->" + to_string(root->left->val));
        }

        if (root->right)
        {
            solve(answer, root->right, temp + "->" + to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> answer;

        if (root == NULL)
        {
            return answer;
        }

        solve(answer, root, to_string(root->val));

        return answer;
    }
};

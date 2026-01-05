#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    void solve(TreeNode *root, int &k, int &answer)
    {
        if (root == NULL || k == 0)
        {
            return;
        }

        solve(root->left, k, answer);
        
        k--;
        if (k == 0)
        {
            answer = root->val;
            return;
        }

        solve(root->right, k, answer);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int answer = -1;
        solve(root, k, answer);

        return answer;
    }
};
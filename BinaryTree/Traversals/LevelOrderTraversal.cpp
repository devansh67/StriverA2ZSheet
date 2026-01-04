#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> answer;

        if (root == NULL)
        {
            return answer;
        }

        q.push(root);
        q.push(NULL);

        vector<int> temp;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            if (it == NULL)
            {
                answer.push_back(temp);
                temp.clear();

                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                temp.push_back(it->val);
                if (it->left != NULL)
                {
                    q.push(it->left);
                }

                if (it->right != NULL)
                {
                    q.push(it->right);
                }
            }
        }

        return answer;
    }
};
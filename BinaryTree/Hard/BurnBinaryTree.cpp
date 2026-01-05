#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

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
    void preorderTraversal(TreeNode *root, TreeNode *parent, unordered_map<TreeNode *, TreeNode *> &mp, int &start, TreeNode *&startNode)
    {
        if (root == NULL)
        {
            return;
        }

        mp[root] = parent;
        if (root->val == start)
        {
            startNode = root;
        }
        preorderTraversal(root->left, root, mp, start, startNode);
        preorderTraversal(root->right, root, mp, start, startNode);
    }

    int amountOfTime(TreeNode *root, int start)
    {
        int time = 0;

        if (root == NULL)
        {
            return time;
        }
        unordered_map<TreeNode *, TreeNode *> mp;
        TreeNode *startNode = NULL;
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;

        preorderTraversal(root, NULL, mp, start, startNode);

        if (startNode == NULL)
        {
            return time;
        }

        q.push(startNode);
        visited.insert(startNode);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();

                if (it->left && !visited.count(it->left))
                {
                    q.push(it->left);
                    visited.insert(it->left);
                }

                if (it->right && !visited.count(it->right))
                {
                    q.push(it->right);
                    visited.insert(it->right);
                }

                if (mp[it] && !visited.count(mp[it]))
                {
                    q.push(mp[it]);
                    visited.insert(mp[it]);
                }
            }
            time++;
        }

        return time - 1;
    }
};